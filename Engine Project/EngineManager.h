#pragma once

#include "Window_BB.h"
#include "GraphicsManager.h"

namespace BlackBoxEngine
{
	class BlackBoxManager
	{
	private:
		GraphicsManager m_graphicsManager;
		GameWindow m_gameWindow;
		// input manager

	public:

		GraphicsManager* GetGraphicsManager() { return &m_graphicsManager; };
		GameWindow* GetGameWindow() { return &m_gameWindow; };

		int StartGame();
	};


}

