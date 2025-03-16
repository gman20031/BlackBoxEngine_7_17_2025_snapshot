#include "GameManager.h"

#include <assert.h>

#include "../Engine Project/System/Log.h"
#include "../Engine Project/Graphics/TextureFactory.h"
#include "../Engine Project/Graphics/RenderingStructs.h"

GameManager::GameManager()
{
	m_windowIndex = m_engineManager.CreateNewWindow(
		"New Game", kDefaultXPos, kDefaultYPos, kDefaultWidth, kDefaultHeight
	);
	
	BlackBoxEngine::Log( "Window Created: Index " + std::to_string(m_windowIndex) );
}

void GameManager::StartGame()
{
	m_engineManager.InitEngine();

	auto& pRenderer = m_engineManager.GetWindow(m_windowIndex)->GetRenderer();
	const auto& linkTexture = BlackBoxEngine::BB_TextureFactory::Create(pRenderer, "../Assets/Link.png");
	const auto& floorTexture = BlackBoxEngine::BB_TextureFactory::Create(pRenderer, "../Assets/Dungeon.png");

	auto test = [&linkTexture, &floorTexture,&pRenderer]() -> void
		{

			if (!pRenderer->DrawTexture(floorTexture))
				BlackBoxEngine::Log(pRenderer->GetErrorStr());
		};

	//m_engineManager.SetGraphicsTest(std::move(test));

	m_engineManager.m_keepRunning = true;
	m_engineManager.StartEngine();

}
