#pragma once

#include <Actors/Component.h>
#include <System/StringHash.h>

class DoorLogic : public BlackBoxEngine::Component
{
    GENERATE_ID("DoorLogic");
public:
    inline static constexpr uint32_t kDoorOpenedMessage = BlackBoxEngine::StringHash("Door Opened");
private:
    inline static constexpr bool m_openedOnPickup = true;
    inline static constexpr const char* m_openTexturePath = "../Assets/Hall.png";
    inline static constexpr const char* m_closedTexturePath = "../Assets/Door.png";
    bool m_keyObtained = false; // todo: move to player inventory component.
    bool m_closed = true;
private:
    void KeyObtained();
    void Open();
public:
    DoorLogic(BlackBoxEngine::Actor* pActor) : Component(pActor) {/*EMPTY*/ };

    virtual void Start() override;
    virtual void OnCollide(BlackBoxEngine::Actor* pActor) override;
};
