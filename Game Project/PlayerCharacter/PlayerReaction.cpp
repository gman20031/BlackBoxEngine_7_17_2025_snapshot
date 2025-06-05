#include "PlayerReaction.h"

#include <BlackBoxManager.h>
#include <System/Log.h>

#include "../GameActors/Enemy.h"
#include "../GameActors/Key.h"
#include "../GameActors/Goal.h"

using namespace BlackBoxEngine;

void PlayerReaction::FoundKey()
{
    BB_LOG(LogType::kMessage, "Player Found key, and door is now unlocked");
}

void PlayerReaction::PlayerHit(Message& message)
{
    assert(*message.pReciever == *m_pOwner);
    auto* pActor = message.pSender;
    BB_LOG(LogType::kMessage, "Player was hit by actor id'" , pActor->GetId(), "\'");
}

void PlayerReaction::GoalFound()
{
    BB_LOG(LogType::kMessage, "Player has found the goal!");
}

void PlayerReaction::Start()
{
    auto* pMessager = BlackBoxEngine::BlackBoxManager::Get()->m_pMessagingManager;
    
    // player hit reaction
    // all equivilant statements
    // pMessager->RegisterListenerString("Player Attacked", [this](Message& message) {PlayerHit(message); });
    // pMessager->RegisterListenerString(StringHash("Player Attacked"), [this](Message& message) {PlayerHit(message); })
    pMessager->RegisterListener(EnemyLogic::kHitPlayerMessage, [this](Message& message) {PlayerHit(message); });

    // player found key reaction
    pMessager->RegisterListener(KeyLogic::kKeyObtainedEvent, [this]([[maybe_unused]]Message& message) { FoundKey(); });

    // player found goal
    pMessager->RegisterListener(GameGoal::kGoalFoundMessage, [this]([[maybe_unused]] Message& message) {
        if( *message.pReciever == *m_pOwner)
            GoalFound();
    });

}
