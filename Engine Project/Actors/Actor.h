#pragma once

#include <memory>
#include <unordered_map>

#include "stdint.h"
#include "Component.h"

class ActorManager;

namespace BlackBoxEngine
{
	class Actor
	{
	public:
		friend bool operator==(const Actor& lhs, const Actor& rhs);
		using ComponentPtr = std::unique_ptr<Component>;
		using Id_t = uint32_t;

	private:
		ActorManager* m_pActorManager = nullptr;
		std::unordered_map<Id_t, ComponentPtr> m_ComponentMap;

	public:
		Actor(ActorManager* pManager);

		template<SubComponent Component_t> Component_t* AddComponent();
		Component* AddComponent(ComponentPtr&& pNewComponent, Id_t componentId);
		[[nodiscard("Component Unused")]] Component* GetComponent(Id_t componentId);
		template<SubComponent Component_t> [[nodiscard("Component unused")]] Component_t* GetComponent();
		[[nodiscard]] const std::unordered_map<Id_t, ComponentPtr >& GetAllComponents() const;

		//void Init(); // Commented out until needed
		void Update();
		void Render();
		void Start();
	};

	template<SubComponent Component_t>
	inline Component_t* Actor::AddComponent()
	{
		m_ComponentMap.try_emplace(Component_t::s_id, std::make_unique<Component_t>(this));
		return static_cast<Component_t*> (GetComponent(Component_t::s_id));
	}

	template<SubComponent Component_t>
	inline Component_t* Actor::GetComponent()
	{
		return static_cast<Component_t*> (GetComponent(Component_t::s_id));
	}

	template<SubComponent Component_t>
	const Actor::ComponentPtr& FindOrCreateComponent(Actor* pActor)

}// BlackBoxEngine

