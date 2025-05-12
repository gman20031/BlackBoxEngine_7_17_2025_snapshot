#include "PlayerMovement.h"

#include "../../Engine Project/Actors/ActorManager.h"

using namespace BlackBoxEngine;

PlayerMovement::PlayerMovement(BlackBoxEngine::Actor* pActor)
    : Component(pActor)
{
    m_playerTranslator = FindOrCreateComponent<TranslationComponent>(pActor);
}

void PlayerMovement::Start()
{

}

void PlayerMovement::Update()
{

}
