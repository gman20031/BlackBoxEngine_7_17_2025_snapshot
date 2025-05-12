#include "TranslationComponent.h"

#include "../../System/XML/tinyxml2.h"
#include "../../System/Log.h"

namespace BlackBoxEngine
{
    void TranslationComponent::Update()
    {
        m_position += m_velocity;
    }

    void TranslationComponent::Load(const XMLElementParser parser)
    {
        auto pVelocity = parser.GetChildElement("Velocity");
        auto pPosition = parser.GetChildElement("Position");
        auto pRotation = parser.GetChildElement("Rotation");

        pVelocity.GetChildVariable("X", &m_velocity.x);
        pVelocity.GetChildVariable("Y", &m_velocity.y);

        pPosition.GetChildVariable("X", &m_position.x);
        pPosition.GetChildVariable("Y", &m_position.y);

        pRotation.GetChildVariable("X", &m_rotation.x);
        pRotation.GetChildVariable("Y", &m_rotation.y);
    }

    void TranslationComponent::Save(XMLElementParser parser)
    {
        auto pVelocity = parser.InsertNewChild("Velocity");
        auto pPosition = parser.InsertNewChild("Position");
        auto pRotation = parser.InsertNewChild("Rotation");

        pVelocity.NewChildVariable("X", m_velocity.x);
        pVelocity.NewChildVariable("Y", m_velocity.y);

        pPosition.NewChildVariable("X", m_position.x);
        pPosition.NewChildVariable("Y", m_position.y);

        pRotation.NewChildVariable("X", m_rotation.x);
        pRotation.NewChildVariable("Y", m_rotation.y);
    }
}