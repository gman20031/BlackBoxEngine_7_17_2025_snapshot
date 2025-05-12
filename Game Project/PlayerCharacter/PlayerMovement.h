#pragma once

#include "../../Engine Project/Actors/Component.h"
#include "../../Engine Project/Actors/EngineComponents/TranslationComponent.h"
#include "../../Engine Project/Input/InputManager.h"

class PlayerMovement : public BlackBoxEngine::Component
{
    GENERATE_ID("PlayerMovement");

    BlackBoxEngine::TranslationComponent* m_playerTranslator;

    static constexpr BlackBoxEngine::KeyCode kMoveUp    = BlackBoxEngine::KeyCode::kW;
    static constexpr BlackBoxEngine::KeyCode kMoveLeft  = BlackBoxEngine::KeyCode::kA;
    static constexpr BlackBoxEngine::KeyCode kMoveDown  = BlackBoxEngine::KeyCode::kS;
    static constexpr BlackBoxEngine::KeyCode kMoveRight = BlackBoxEngine::KeyCode::kD;

public:
    PlayerMovement(BlackBoxEngine::Actor* pActor);

    virtual void Start() override;
    virtual void Update() override;
};

