#pragma once

#include "../Engine Project/EngineManager.h"

class GameManager
{
    BlackBoxEngine::BlackBoxManager* m_pEngineManager;
    size_t m_sceneIndex = 0;

private: // Variables
	inline static constexpr int kDefaultXPos	= 200;
	inline static constexpr int kDefaultYPos	= 200;
	inline static constexpr int kDefaultWidth	= 1024;
	inline static constexpr int kDefaultHeight	= 786;

private: // functions
    void InitGame();

public:
	GameManager();

	void StartGame();
};


