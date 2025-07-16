#include "Goal.h"

#include <BlackBoxManager.h>
#include "../PlayerCharacter/PlayerHealth.h"

using namespace BlackBoxEngine;

void GameGoal::Start()
{
}

void GameGoal::OnCollide(BlackBoxEngine::Actor* pActor)
{
    if (!pActor->GetComponent<PlayerHealth>())
        return;
    auto* pMessager = BlackBoxManager::Get()->m_pMessagingManager;
    BB_LOG(LogType::kMessage, "Goal was found");
    pMessager->EnqueueMessage(kGoalFoundMessage, m_pOwner, pActor);
    BlackBoxManager::Get()->m_pActorManager->DestroyActor(m_pOwner);
}
