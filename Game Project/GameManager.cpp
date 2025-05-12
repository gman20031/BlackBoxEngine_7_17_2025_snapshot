#include "GameManager.h"

#include <assert.h>

#include "../Engine Project/System/SimpleTimingSystem.h"

#include "../Engine Project/System/Log.h"
#include "../Engine Project/Actors/EngineComponents/SpriteComponent.h"
#include "../Engine Project/Graphics/RenderingStructs.h"

#include "PlayerCharacter/PlayerMovement.h"

using namespace BlackBoxEngine;
GameManager::GameManager()
{
    m_pEngineManager = BlackBoxManager::Get();
	m_sceneIndex = m_pEngineManager->CreateSceneWindow(
		"New Game", kDefaultXPos, kDefaultYPos, kDefaultWidth, kDefaultHeight
	);
	
    BB_LOG(BlackBoxEngine::LogType::kMessage, "Scene created : index ", m_sceneIndex);
}

void GameManager::InitGame()
{
    auto* pActorManager = m_pEngineManager->GetScene(m_sceneIndex)->m_pSceneActorManager;
    pActorManager->LoadActor("../Assets/Actors/Background.xml");
    pActorManager->LoadActor("../Assets/Actors/Player.xml");
    pActorManager->LoadActor("../Assets/Actors/Goriya.xml");

    //auto& pActor = pActorManager->LoadActor("../Assets/Actors/Test.xml");
    //pActor->GetComponent<SpriteComponent>()->SetTexture("../Assets/Link.png");
    //pActor->GetComponent<SpriteComponent>()->SetDimensions(32,32);
    //BlackBoxEngine::ActorXMLParser::SaveActor(pActor, "Player");
}

void GameManager::StartGame()
{
	m_pEngineManager->InitEngine();
    InitGame();

    BB_LOG(LogType::kMessage, "Startup time " , SimpleTimer::StopTimer("Startup time") );

	m_pEngineManager->m_keepRunning = true;
	m_pEngineManager->StartEngine();

}
