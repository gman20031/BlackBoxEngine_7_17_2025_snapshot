#pragma once

#include <System/StringHash.h>
#include <Actors/Component.h>

class PlayerHealth : public BlackBoxEngine::Component
{
    GENERATE_ID("PlayerHealth");
    static constexpr uint32_t kPlayerDiedMessage = BlackBoxEngine::StringHash("PlayerDied");

    int m_health = 1;
    int m_maxHealth = 10;

private:
    void PlayerDied();
    void CheckHealth();
public:
    PlayerHealth(BlackBoxEngine::Actor* pActor) : Component(pActor) {/*EMPTY*/}

    virtual void Start() override;
    void ModifyHealth(int change);
    void SetHealth(int newHealth);
    int GetHealth() const { return m_health; }
};