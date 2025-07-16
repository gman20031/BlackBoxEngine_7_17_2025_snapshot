#include "Key.h"

#include <BlackBoxManager.h>

#include "../PlayerCharacter/PlayerMovement.h"

using namespace BlackBoxEngine;

KeyLogic::KeyLogic(Actor* pActor)
    : Component(pActor)
{
}

void KeyLogic::Start()
{

}

void KeyLogic::OnCollide(BlackBoxEngine::Actor* pActor)
{
    PlayerMovement* pPlayerMovement = pActor->GetComponent<PlayerMovement>();
    if(pPlayerMovement)
    {
        BlackBoxManager::Get()->m_pMessagingManager->EnqueueMessage(kKeyObtainedEvent, m_pOwner, pActor);
        BlackBoxManager::Get()->m_pActorManager->DestroyActor(m_pOwner->GetId());
    }

}