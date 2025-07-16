#include "GameManager.h"

#include <assert.h>

#include "../Engine Project/System/SimpleTimingSystem.h"
#include "../Engine Project/System/Log.h"

using namespace BlackBoxEngine;
GameManager::GameManager()
    : m_pEngineManager(BlackBoxManager::NewSingleton())
{
	m_pEngineManager->CreateWindow(
		"New Game", kDefaultXPos, kDefaultYPos, kDefaultWidth, kDefaultHeight
	);
	
    BB_LOG(BlackBoxEngine::LogType::kMessage, "Window created");
}

GameManager::~GameManager()
{
    if(m_pEngineManager)
        m_pEngineManager->DeleteSingleton();
}

void GameManager::InitGame()
{
    auto* pActorManager = m_pEngineManager->m_pActorManager;
    pActorManager->LoadLevel("../Assets/Levels/ZeldaGame.xml");

}

void GameManager::Launch()
{
    SimpleTimer* pTimer = new SimpleTimer;
    pTimer->StartTimer();

    assert(m_pEngineManager);
    m_pEngineManager->InitEngine();
    InitGame();

    BB_LOG(LogType::kMessage, "Startup time ", pTimer->GetDeltaTime() );
    delete pTimer;

    m_pEngineManager->RunEngine();
}
