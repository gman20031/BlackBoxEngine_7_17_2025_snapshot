#include "GameManager.h"

#include <assert.h>

#include "../Engine Project/Auxillary/Log.h"


GameManager::GameManager()
{
	m_windowIndex = m_engineManager.CreateNewWindow(
		"New Game", 200, 200, 1024, 786
	);

	//BlackBoxEngine::Log(m_windowIndex);

}

void GameManager::StartGame()
{

	m_engineManager.GetWindow(m_windowIndex)->StartWindow();

	m_engineManager.StartEngine();

}
