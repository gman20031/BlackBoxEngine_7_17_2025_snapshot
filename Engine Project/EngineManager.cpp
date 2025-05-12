#include "EngineManager.h"

#include <SDL.h>
#include <SDL_image.h>

#include <ranges>
#include <algorithm>

namespace BlackBoxEngine
{
    BlackBoxManager::~BlackBoxManager()
    {
        if (m_pEngineActorManager)
            delete m_pEngineActorManager;
        if (m_pInputManager)
            delete m_pInputManager;
        if (m_pMessagingManager)
            delete m_pMessagingManager;
    }

    void BlackBoxManager::HandleSdlEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_KEY_DOWN:
                m_pInputManager->AddKeyDown((KeyCode)event.key.scancode);
                break;
            case SDL_EVENT_KEY_UP:
                m_pInputManager->RemoveKeyDown((KeyCode)event.key.scancode);
                break;
            case SDL_EVENT_QUIT:
                m_keepRunning = false;
                break;
            }
        }
    }

    size_t BlackBoxManager::CreateSceneWindow( const char* title, int xPos, int yPos, int width, int height)
    {
        auto pWindow = std::make_unique<BB_Window>(title, xPos, yPos, width, height);
        m_scenes.emplace_back( std::make_unique<BB_Scene>(std::move(pWindow)) );
        return m_scenes.size() - 1;
    }

    int BlackBoxManager::StartEngine()
    {
        while (m_keepRunning)
        {

            /// Update global Systems
            m_pInputManager->Update();
            HandleSdlEvents();
            // the engine le

            /// Perform loop for each scene in the engine.
            for (auto& pScene : m_scenes)
            {
                auto* pRenderer = pScene->m_pWindow->GetRenderer();
                pRenderer->ClearRenderer();

                // scene actors
                pScene->m_pSceneActorManager->Update();
                pScene->m_pSceneActorManager->Render();

                pRenderer->Present();

            }
        }
        return 0;
    }

    int BlackBoxManager::InitEngine()
    {
        m_pEngineActorManager = new ActorManager;
        m_pInputManager = new InputManager;
        m_pMessagingManager = new MessagingManager;

        for (auto& pScene : m_scenes)
        {
            if (pScene->m_pWindow->StartWindow() != 0)
                m_keepRunning = false;
        }

        return 0;
    }

    BlackBoxManager* BlackBoxManager::Get()
    {
        static BlackBoxManager engineManager;
        return &engineManager;
    }
}
