#pragma once

#include "../../Engine Project/Actors/Component.h"
#include "../../Engine Project/Actors/ActorManager.h"
#include "../../Engine Project/Actors/EngineComponents/MoverComponent.h"
#include "../../Engine Project/Actors/EngineComponents/TransformComponent.h"
#include "../../Engine Project/Input/InputManager.h"

class PlayerMovement : public BlackBoxEngine::Component
{
    GENERATE_ID("PlayerMovement");

    BlackBoxEngine::MoverComponent* m_pMover;
    BlackBoxEngine::TransformComponent* m_pTransform;

    uint64_t m_callbackCodes[8];
    static constexpr BlackBoxEngine::KeyCode kUpKey    = BlackBoxEngine::KeyCode::kW;
    static constexpr BlackBoxEngine::KeyCode kLeftKey  = BlackBoxEngine::KeyCode::kA;
    static constexpr BlackBoxEngine::KeyCode kDownKey  = BlackBoxEngine::KeyCode::kS;
    static constexpr BlackBoxEngine::KeyCode kRightKey = BlackBoxEngine::KeyCode::kD;

    static constexpr float kPlayerSpeed = 180;

public:
    PlayerMovement(BlackBoxEngine::Actor* pActor);
    ~PlayerMovement();

    virtual void Start() override;
};

