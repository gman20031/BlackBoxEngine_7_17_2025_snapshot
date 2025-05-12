#include "ComponentFactory.h"

#include <tuple>

#include "EngineComponents/SpriteComponent.h"
#include "EngineComponents/TranslationComponent.h"

namespace BlackBoxEngine
{
    static std::tuple
    <
        ComponentFactory::Registrar<TranslationComponent>,
        ComponentFactory::Registrar<SpriteComponent>
    > EngineRegistrar;

    Component* ComponentFactory::NewComponent(Component::Id id, Actor* pActor)
    {
        auto it = Map().find(id);
        if (it == Map().end())
        {
            BB_LOG(LogType::kFailure, "Attempted to create component that was not registered ID", id);
            return nullptr;
        }
        return it->second(pActor);
    }
}

