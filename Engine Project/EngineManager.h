#pragma once

#include <vector>
#include <memory>

#include "Graphics/Window.h"
#include "Graphics/Renderer.h"

namespace BlackBoxEngine
{
	class BlackBoxManager
	{
	public:
		using RendererPtr = std::unique_ptr<BB_Renderer>;
		using WindowPtr = std::unique_ptr<BB_Window>;
		using TestFunctionPtr = void(*)(const RendererPtr&);
	private:
		std::vector< WindowPtr > m_allWindows;
		TestFunctionPtr m_pGraphicsTestFunction = nullptr;

		// ActorManager
		 
		// input manager
	
	public:
		bool m_keepRunning = false;

	public:
		const WindowPtr& GetWindow(size_t index) { return m_allWindows[index]; };
		[[nodiscard("index not caught after creating window")]] size_t CreateNewWindow
			(const char* title, int xPos, int yPos, int width, int height);
		
		void SetGraphicsTest(TestFunctionPtr pTestFunction) { m_pGraphicsTestFunction = pTestFunction; }
		int StartEngine();
	};


}

