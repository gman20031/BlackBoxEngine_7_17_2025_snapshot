#include "PlayerMovement.h"

#include "../../Engine Project/BlackBoxManager.h"
#include "../../Engine Project/Input/InputManager.h"
#include "../../Engine Project/Actors/Collision/CollisionManager.h"
#include "../../Engine Project/Actors/EngineComponents/MovementBlocker.h"

using namespace BlackBoxEngine;

PlayerMovement::PlayerMovement(BlackBoxEngine::Actor* pActor)
    : Component(pActor)
{
    m_pTransform = pActor->GetComponent<TransformComponent>();
    m_pMover = pActor->GetComponent<MoverComponent>();
}

PlayerMovement::~PlayerMovement()
{
    using enum InputManager::InputType;
    // bad and annoying - remembering codes suck
    auto* pInputManager = BlackBoxManager::Get()->m_pInputManager;
    for (int i = 0; i < 4; ++i)
        pInputManager->UnsubscribeKey(m_callbackCodes[i], kKeyDown);
    for (int i = 4; i < 8; ++i)
        pInputManager->UnsubscribeKey(m_callbackCodes[i], kKeyUp);
}

void PlayerMovement::Start()
{
    auto* pInputManager = BlackBoxManager::Get()->m_pInputManager;
    using enum InputManager::InputType;
    int index = 0;

    // Key Down
    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kUpKey, kKeyDown,
        [this]() {m_pMover->m_velocity.y -= kPlayerSpeed; }
    );

    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kDownKey, kKeyDown,
        [this]() {m_pMover->m_velocity.y += kPlayerSpeed; }
    );

    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kRightKey, kKeyDown,
        [this]() {m_pMover->m_velocity.x += kPlayerSpeed; }
    );

    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kLeftKey, kKeyDown,
        [this]() {m_pMover->m_velocity.x -= kPlayerSpeed; }
    );

    // Key Up
    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kUpKey, kKeyUp,
        [this]() {m_pMover->m_velocity.y += kPlayerSpeed; }
    );

    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kDownKey, kKeyUp,
        [this]() {m_pMover->m_velocity.y -= kPlayerSpeed; }
    );

    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kRightKey, kKeyUp,
        [this]() {m_pMover->m_velocity.x -= kPlayerSpeed; }
    );

    m_callbackCodes[index++] = pInputManager->SubscribeToKey(kLeftKey, kKeyUp,
        [this]() {m_pMover->m_velocity.x += kPlayerSpeed; }
    );

}
