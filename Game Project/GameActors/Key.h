#pragma once

#include <Actors/Component.h>
#include <System/StringHash.h>

class KeyLogic : public BlackBoxEngine::Component
{
    GENERATE_ID("KeyLogic");
public:
    inline static constexpr uint32_t kKeyObtainedEvent = BlackBoxEngine::StringHash("KeyObtained");
    // on collide, send message -> keyPickedUp
public:
    KeyLogic(BlackBoxEngine::Actor* pActor);

    virtual void Start() override;
    virtual void OnCollide(BlackBoxEngine::Actor* pActor) override;
};
