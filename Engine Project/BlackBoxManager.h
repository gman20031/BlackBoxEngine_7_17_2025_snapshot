#pragma once

#include <vector>
#include <memory>
#include <functional>

#include "Graphics/Window.h"
#include "Graphics/Renderer.h"
#include "Graphics/Scene.h"
#include "Actors/ActorManager.h"
#include "Input/InputManager.h"
#include "System/MessageManager.h"

namespace BlackBoxEngine
{
	class BlackBoxManager
	{
	public:
        using WindowPtr = std::unique_ptr<BB_Window>;

	private:
        inline static constexpr float kCollisionBufferSize = 0;
        static BlackBoxManager* m_pSingletonManager;
        WindowPtr m_pWindow;
        double m_deltaTime = 0;


    public:
		bool m_keepRunning = false;
        CollisionManager* m_pCollisionManager = nullptr;
		ActorManager* m_pActorManager = nullptr;
        InputManager* m_pInputManager = nullptr;
        MessagingManager* m_pMessagingManager = nullptr;


	public:
        ~BlackBoxManager();
        BlackBoxManager(const BlackBoxManager&) = delete;
        BlackBoxManager(BlackBoxManager&&) = delete;
        void operator=(const BlackBoxManager&) = delete;
        void operator=(BlackBoxManager&&) = delete;

        const WindowPtr& GetWindow() { return m_pWindow; }
		[[nodiscard("index not caught after creating window")]] void CreateWindow
			(const char* title, int xPos, int yPos, int width, int height);
        double GetDeltaTime() const { return m_deltaTime; }

		int RunEngine();
		int InitEngine();

        [[nodiscard("Manager not being used")]] static BlackBoxManager* Get();
        static BlackBoxManager* NewAndInitEngine();
        static BlackBoxManager* NewSingleton();
        static void DeleteSingleton();

    private: // functions
        void HandleSdlEvents();
        void CheckEngineInitialized();
        BlackBoxManager() = default;
    };


}

