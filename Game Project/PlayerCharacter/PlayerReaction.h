#pragma once

#include <System/MessageManager.h>
#include <System/StringHash.h>
#include <Actors/Component.h>

class PlayerReaction : public BlackBoxEngine::Component
{
    GENERATE_ID("PlayerReaction");

    BlackBoxEngine::MessagingManager* m_pMessagingManager = nullptr;

private:
    void FoundKey();
    void PlayerHit(BlackBoxEngine::Message& message);
    void GoalFound();
public:
    PlayerReaction(BlackBoxEngine::Actor* pActor) : Component(pActor) {/*EMPTY*/ }

    virtual void Start() override;
};

//pMessager->RegisterListener(EnemyLogic::kHitPlayerMessage, [this](Message& message) { PlayerDied(); });
