#include "GameManager.h"

#include <assert.h>

#include "../Engine Project/Auxillary/Log.h"


void GameManager::SetupRenderingTest(const BlackBoxEngine::BlackBoxManager::RendererPtr& pRenderer)
{
	pRenderer->SetRenderDrawColor(BlackBoxEngine::ColorPresets::green);

	if ( !pRenderer->DrawLine({ 0,0 }, { 100,100 }) )
		BlackBoxEngine::Log(pRenderer->GetErrorStr());

	BlackBoxEngine::BB_Rectangle myRect(
		50, 50,
		500, 500
	);
	if (!pRenderer->DrawRectFilled(myRect))
		BlackBoxEngine::Log( pRenderer->GetErrorStr() );
}

GameManager::GameManager()
{
	m_windowIndex = m_engineManager.CreateNewWindow(
		"New Game", kDefaultXPos, kDefaultYPos, kDefaultWidth, kDefaultHeight
	);
	
	BlackBoxEngine::Log( "Window Created: Index " + std::to_string(m_windowIndex) );
}

void GameManager::StartGame()
{
	m_engineManager.SetGraphicsTest(&SetupRenderingTest);
	m_engineManager.m_keepRunning = true;
	m_engineManager.StartEngine();

}
