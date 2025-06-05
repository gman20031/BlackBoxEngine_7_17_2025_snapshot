#pragma once

#include <Actors/Component.h>

namespace BlackBoxEngine 
{
    class BlackBoxManager;
}

class EnemyLogic : public BlackBoxEngine::Component
{
    GENERATE_ID("EnemyLogic");
    BlackBoxEngine::BlackBoxManager* m_pEngine = nullptr;
    inline static constexpr uint32_t kHitPlayerMessage = BlackBoxEngine::StringHash("Player Attacked");
    static constexpr int kDamage = 1;

public:
    EnemyLogic(BlackBoxEngine::Actor* pActor) : Component(pActor) {/*EMPTY*/}

    virtual void Start() override;
    virtual void OnCollide(BlackBoxEngine::Actor* pOther) override;


};