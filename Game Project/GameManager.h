#pragma once

#include "../Engine Project/EngineManager.h"

class GameManager
{
	BlackBoxEngine::BlackBoxManager m_engineManager;

	size_t m_windowIndex = 0;

public:
	GameManager();

	BlackBoxEngine::BlackBoxManager& Engine() { return m_engineManager; }

	void StartGame();
};


