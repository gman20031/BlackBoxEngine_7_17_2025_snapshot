#pragma once

#include "../Engine Project/EngineManager.h"

class GameManager
{
	BlackBoxEngine::BlackBoxManager m_engineManager;

	size_t m_windowIndex = 0;

private: // Variables
	inline static constexpr int kDefaultXPos	= 200;
	inline static constexpr int kDefaultYPos	= 200;
	inline static constexpr int kDefaultWidth	= 1024;
	inline static constexpr int kDefaultHeight	= 786;


private: // functions
	static void SetupRenderingTest(const BlackBoxEngine::BlackBoxManager::RendererPtr& pRenderer);

public:
	GameManager();

	BlackBoxEngine::BlackBoxManager& Engine() { return m_engineManager; }

	void StartGame();
};


