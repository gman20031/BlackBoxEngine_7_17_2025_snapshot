#include "ActorManager.h"

#include "../System/Log.h"
#include "../System/XML/BlackBoxXMLParser.h"
#include "../System/XML/tinyxml2.h"

namespace BlackBoxEngine
{
    void ActorManager::Update()
    {
        for (auto& [id, pActor] : m_allActors)
            pActor->Update();
    }

    void ActorManager::Start()
    {
        for (auto& [id, pActor] : m_allActors)
            pActor->Start();
    }

    void ActorManager::Render()
    {
        for (auto& [id, pActor] : m_allActors)
            pActor->Render();
    }

    const ActorManager::ActorPtr& ActorManager::NewActor()
    {
        Actor::Id id = NextId();
        auto [pair, test] = m_allActors.emplace(id, std::make_unique<Actor>(this, id) );
        if (!test)
            BB_LOG(LogType::kError, "Actor emplace failed");
        return pair->second;
    }

    const ActorManager::ActorPtr& ActorManager::LoadActor(const char* filePath)
    {
        auto parser = ActorXMLParser(filePath);
        auto& pActor = NewActor();
        while ( pActor->ParseComponent(parser.NextComponent()) );
        return pActor;
    }

    Actor::Id ActorManager::NextId()
    {
        Actor::Id nextId = m_nextActorId;
        ++m_highestId;
        m_nextActorId = m_highestId;
        return nextId;
    }

    void ActorManager::RemoveActor(Actor::Id id)
    {
        m_nextActorId = id;
        m_allActors.erase(id);
    }
}