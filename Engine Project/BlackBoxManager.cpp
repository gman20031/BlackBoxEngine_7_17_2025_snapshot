#include "BlackBoxManager.h"

#include <SDL.h>
#include <SDL_image.h>

#include <algorithm>

#include "System/SimpleTimingSystem.h"
#include "Actors/ActorManager.h"

namespace BlackBoxEngine
{
    BlackBoxManager* BlackBoxManager::m_pSingletonManager{ nullptr };

#ifdef _DEBUG
    void BlackBoxManager::CheckEngineInitialized()
    {
        if (!m_pActorManager)
            BB_LOG(LogType::kFailure, "Engine has no actor Manager");
        if (!m_pInputManager)
            BB_LOG(LogType::kFailure, "Engine has no input Manager");
        if (!m_pMessagingManager)
            BB_LOG(LogType::kFailure, "Engine has no message Manager");
        if (!m_pCollisionManager)
            BB_LOG(LogType::kFailure, "Engine has no collision Manager");
        if (!m_pWindow)
            BB_LOG(LogType::kFailure, "Engine has no window");
    }
#endif // _DEBUG


    BlackBoxManager::~BlackBoxManager()
    {
        if (m_pActorManager)
            delete m_pActorManager;
        if (m_pInputManager)
            delete m_pInputManager;
        if (m_pMessagingManager)
            delete m_pMessagingManager;
        if (m_pCollisionManager)
            delete m_pCollisionManager;
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

    void BlackBoxManager::CreateWindow( const char* pWindowTitle, int xPos, int yPos, int width, int height)
    {
        m_pWindow = std::make_unique<BB_Window>(pWindowTitle, xPos, yPos, width, height);
    }

    int BlackBoxManager::RunEngine()
    {
#ifdef _DEBUG
        BB_LOG(LogType::kMessage, "Game started in debug mode");
        CheckEngineInitialized();
#endif _DEBUG
        // Start all the actors in every active scene
        m_pActorManager->Start();

        SimpleTimer timer;
        timer.StartTimer();

        while (m_keepRunning)
        {
            //BB_LOG(LogType::kMessage, "NEW UPDATE CYCLE");
            m_deltaTime = timer.GetDeltaTime();
            timer.StartTimer();

            /// Update global Systems
            HandleSdlEvents();
            m_pInputManager->Update();

            auto* pRenderer = m_pWindow->GetRenderer();
            pRenderer->Clear();

            m_pActorManager->Update();
            m_pActorManager->Render();
#ifdef _DEBUG
            m_pCollisionManager->DebugDraw();
#endif _DEBUG
            m_pMessagingManager->SendQueuedMessages();

            pRenderer->Present();

        }

        return 0;
    }

    int BlackBoxManager::InitEngine()
    {
        m_pInputManager = new InputManager;
        m_pMessagingManager = new MessagingManager;
        m_pActorManager = new ActorManager;
        m_pCollisionManager = new CollisionManager
            (-kCollisionBufferSize, -kCollisionBufferSize,
            (float)m_pWindow->GetWidth() + kCollisionBufferSize,
            (float)m_pWindow->GetHeight() + kCollisionBufferSize);

        m_keepRunning = true;

        assert(m_pWindow);
        if (m_pWindow->StartWindow() != 0)
            m_keepRunning = false;

        return 0;
    }

    BlackBoxManager* BlackBoxManager::Get()
    {
        assert(m_pSingletonManager);
        return m_pSingletonManager;
    }

    BlackBoxManager* BlackBoxManager::NewAndInitEngine()
    {
        NewSingleton();
        m_pSingletonManager->InitEngine();
        return m_pSingletonManager;
    }

    BlackBoxManager* BlackBoxManager::NewSingleton()
    {
        DeleteSingleton();
        m_pSingletonManager = new BlackBoxManager;
        return m_pSingletonManager;
    }

    void BlackBoxManager::DeleteSingleton()
    {
        if (m_pSingletonManager)
        {
            delete m_pSingletonManager;
            m_pSingletonManager = nullptr;
        }
    }
}
