#include "GameTestingComponent.h"

#include "../../Engine Project/System/Debugging.h"
#include "../../Engine Project/BlackBoxManager.h"
#include "../../Engine Project/Input/InputManager.h"
#include "../../Engine Project/Actors/ActorManager.h"
#include "../../Engine Project/Actors/Collision/CollisionManager.h"

using namespace BlackBoxEngine;

void GameTestingComponent::Start()
{
    // test

#if _DEBUG
    {
    auto* pInputManager = BlackBoxManager::Get()->m_pInputManager;
    using enum InputManager::InputType;
        pInputManager->SubscribeToKey(KeyCode::kP, kKeyDown,
            []() { BlackBoxManager::Get()->m_pCollisionManager->DumpToFile("CollisionDump.txt"); }
        );

        pInputManager->SubscribeToKey(KeyCode::kO, kKeyDown,
            [this]() {
                auto& pActor = BlackBoxManager::Get()->m_pActorManager->LoadActor("../Assets/Actors/Block.xml");
                TransformComponent* pTransform = pActor->GetComponent<TransformComponent>();
                auto pos = m_pOwner->GetComponent<TransformComponent>()->m_position;
                pos.x -= 70;
                pTransform->m_position = pos;
            }
        );
        AABBColliderComponent* pCollider = m_pOwner->GetComponent<AABBColliderComponent>();

        pInputManager->SubscribeToKey(KeyCode::kL, kKeyDown,
            [this, pCollider]() {
                pCollider->ToggleCollision();
            }
        );
    }
#endif

}


