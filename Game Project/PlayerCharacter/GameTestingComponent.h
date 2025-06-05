#pragma once

#include <Actors/Component.h>
#include <Actors/ActorManager.h>
#include <Input/InputManager.h>

class GameTestingComponent : public BlackBoxEngine::Component
{
    GENERATE_ID("GameTestingComponent");

public:
    GameTestingComponent(BlackBoxEngine::Actor* pActor) : Component(pActor) {/*EMPTY*/}

    virtual void Start() override;

};
