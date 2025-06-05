#include "Door.h"

#include <BlackBoxManager.h>
#include <Graphics/Texture.h>
#include <Actors/EngineComponents/SpriteComponent.h>
#include <Actors/Collision/AABBColliderComponent.h>

#include "Key.h"
#include "../PlayerCharacter/PlayerHealth.h"

using namespace BlackBoxEngine;

void DoorLogic::KeyObtained()
{
    m_keyObtained = true;
    if constexpr (m_openedOnPickup)
        Open();
}

void DoorLogic::Open()
{
    assert(m_closed);
    auto* pSprite = m_pOwner->GetComponent<SpriteComponent>();
    auto* pCollider = m_pOwner->GetComponent<AABBColliderComponent>();
    pSprite->SetTexture(m_openTexturePath);
    pCollider->DisableCollision();
}

void DoorLogic::Start()
{
    BlackBoxManager::Get()->m_pMessagingManager->RegisterListener
    (
        KeyLogic::kKeyObtainedEvent,
        [this]([[maybe_unused]]Message& message) {KeyObtained(); }
    );
}

void DoorLogic::OnCollide(BlackBoxEngine::Actor* pActor)
{
    if (!pActor->GetComponent<PlayerHealth>())
        return;
    if (m_keyObtained && m_closed)
        Open();
}

