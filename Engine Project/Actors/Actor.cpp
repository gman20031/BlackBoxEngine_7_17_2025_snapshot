#include "Actor.h"

#include <algorithm>

BlackBoxEngine::Actor::Actor(ActorManager* pManager)
	: m_pActorManager(pManager)
{
}

Component* BlackBoxEngine::Actor::AddComponent(ComponentPtr&& pNewComponent, Id_t componentId)
{
    return nullptr;
}

Component* BlackBoxEngine::Actor::GetComponent(Id_t componentId)
{
    return nullptr;
}

const std::unordered_map<BlackBoxEngine::Actor::Id_t, BlackBoxEngine::Actor::ComponentPtr>&
	BlackBoxEngine::Actor::GetAllComponents() const
{
    // TODO: insert return statement here
}

//void BlackBoxEngine::BB_Actor::Init()
//{
//
//}

void BlackBoxEngine::Actor::Update()
{
	for (const auto& [id, pComponent] : m_ComponentMap)
		pComponent->Update();
}

void BlackBoxEngine::Actor::Render()
{
	for (const auto& [id, pComponent] : m_ComponentMap)
		pComponent->Render();
}

void BlackBoxEngine::Actor::Start()
{
	for ( const auto& [id, pComponent] : m_ComponentMap )
		pComponent->Start();
}
