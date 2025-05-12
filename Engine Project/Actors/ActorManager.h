#pragma once

#include "Actor.h"
#include <unordered_map>

namespace BlackBoxEngine
{
    class ActorManager
    {
        friend struct BB_Scene;
    public:
        using ActorPtr = std::unique_ptr<Actor>;
    private:
        std::unordered_map<Actor::Id , ActorPtr> m_allActors;

        BB_Scene* m_pOwningScene = nullptr;

        Actor::Id m_nextActorId = 0;
        Actor::Id m_highestId = 0;

    private:
        Actor::Id NextId();
    public:
        BB_Scene* OwningScene() const { return m_pOwningScene; }

        const ActorPtr& NewActor();
        const ActorPtr& LoadActor(const char* filePath);
        void RemoveActor(Actor::Id id);
        
        void Update();
        void Start();
        void Render();
    };

};

