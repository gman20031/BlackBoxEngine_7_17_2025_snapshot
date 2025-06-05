#pragma once

#include <Actors/Component.h>
#include <System/StringHash.h>

class GameGoal : public BlackBoxEngine::Component
{
    GENERATE_ID("GameGoal");
public:
    inline static constexpr uint32_t kGoalFoundMessage = BlackBoxEngine::StringHash("Goal Found");
    // on collide, send message -> keyPickedUp
public:
    GameGoal(BlackBoxEngine::Actor* pActor) : Component(pActor) {/*EMPTY*/};

    virtual void Start() override;
    virtual void OnCollide(BlackBoxEngine::Actor* pActor) override;
};
