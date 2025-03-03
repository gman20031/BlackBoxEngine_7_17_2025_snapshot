#include "EngineManager.h"

#include <SDL.h>
#include <SDL_image.h>

#include <ranges>
#include <algorithm>

size_t BlackBoxEngine::BlackBoxManager::CreateNewWindow(
	const char* title,
	int xPos,
	int yPos,
	int width,
	int height)
{
	auto pWindow = std::make_unique<BB_Window>(
		title,
		xPos,
		yPos,
		width,
		height
	);

	m_allWindows.push_back( std::move(pWindow) );

	return m_allWindows.size() - 1;
}

int BlackBoxEngine::BlackBoxManager::StartEngine()
{
	std::ranges::for_each(m_allWindows, [&](const WindowPtr& pWindow)
		{
			if (pWindow->StartWindow() != 0)
				m_keepRunning = false;
		});

	while (m_keepRunning)
	{
		std::ranges::for_each(m_allWindows, [this](const WindowPtr& window)
		{
			auto& pRenderer = window->GetRenderer();
			pRenderer->ClearRenderer();

			m_pGraphicsTestFunction(pRenderer);
			
			pRenderer->Present();
		});

		SDL_Event event;
		while ( SDL_PollEvent(&event) )
		{
			switch (event.type)
			{
			case SDL_EVENT_KEY_DOWN:
				if (event.key.scancode == SDL_SCANCODE_X)
					m_keepRunning = false;
				break;
			case SDL_EVENT_QUIT:
				m_keepRunning = false;
				break;
			}
		}
	
		
	}
    return 0;
}
