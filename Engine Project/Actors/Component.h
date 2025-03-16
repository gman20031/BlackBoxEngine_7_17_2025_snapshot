#pragma once
#include <concepts>
#include "../System/StringHash.h"

class Actor;

////////////////////////////////////////////////////////////
// General Component class
//   constexpr void Start() {}
//   void Start() {}
//   void Render() {}
//   void Update() {}
//   void OnCollide() {}
//	To inherit:
//   add ID_FROM_NAME 
//   and Esnure constructor calls component constructor
////////////////////////////////////////////////////////////
class Component
{
public:
	using id_t = uint32_t;
protected:
	Actor* m_pOwner;
public:
	Component(Actor* pOwner) : m_pOwner(pOwner) { /* EMPTY */ }
	virtual ~Component() = default;
	Component(const Component&) = delete;
	Component& operator=(const Component&) = delete;

	constexpr virtual void Start()  { /* EMPTY */ }
	constexpr virtual void Render() { /* EMPTY */ }
	constexpr virtual void Update() { /* EMPTY */ }
};

////////////////////////////////////////////////////////////
// Concept equivilant to - std::derived_from<T, Component>
////////////////////////////////////////////////////////////
template<class T>
concept SubComponent = std::derived_from<T, Component>;

#define ID_FROM_NAME(name_c_string)	\
public: static inline constexpr Component::id_t s_id = StringHash(name_c_string);


////////////////////////////////////////////////////////////
// compile time counter to ensure each component has a -
// unique Id
////////////////////////////////////////////////////////////
class ComponentStaticIdCounter
{
#define D_NEW_STATIC_ID public: static inline const Component::id_t s_id = ComponentStaticIdCounter::Get()
private:
	static inline Component::id_t m_next = 0;
public:
	static constexpr Component::id_t Get() {
		return m_next++;
	}
};