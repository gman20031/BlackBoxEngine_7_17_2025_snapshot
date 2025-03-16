#pragma once

#include "../Component.h"

namespace BlackBoxEngine
{
	class TranslationComponent : public Component
	{
	public:
		ID_FROM_NAME("TranslationComponent");

	private:

	public:
		TranslationComponent(Actor* pOwner) : Component(pOwner) {/*EMPTY*/ }
	};
}