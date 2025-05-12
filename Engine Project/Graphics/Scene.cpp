#include "Scene.h"

#include <cassert>

BlackBoxEngine::BB_Scene::BB_Scene(std::unique_ptr<BB_Window> pWindow)
{
    assert(pWindow);
    m_pWindow = std::move(pWindow);
    m_pSceneActorManager = new ActorManager;
    m_pSceneActorManager->m_pOwningScene = this;
}

BlackBoxEngine::BB_Scene::~BB_Scene()
{
    assert(m_pSceneActorManager);
    delete m_pSceneActorManager;
}
