#pragma once

#include "../Component.h"
#include "../../System/FVector2.h"

namespace BlackBoxEngine
{
	class TranslationComponent : public Component
	{
	public:
		GENERATE_ID("TranslationComponent");
        TranslationComponent(Actor* pOwner) : Component(pOwner) {/*EMPTY*/ }
        
        FVector2 m_velocity = { 0,0 };
        FVector2 m_position = { 0,0 };
        FVector2 m_rotation = { 0,0 };


        virtual void Update() override;

        virtual void Load(const XMLElementParser parser) override;
        virtual void Save(XMLElementParser parser) override;
    };

}