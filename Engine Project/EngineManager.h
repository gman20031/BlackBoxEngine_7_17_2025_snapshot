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
        //using MessageManager = BB_Observer<
	public:
		using ScenePtr = std::unique_ptr<BB_Scene>;
        using WindowPtr = std::unique_ptr<BB_Window>;

	private:
		std::vector< ScenePtr > m_scenes;

    public:
		bool m_keepRunning = false;
        ActorManager* m_pEngineActorManager = nullptr; // For transitioning or engine level components, not updated every frame.
        InputManager* m_pInputManager = nullptr;
        MessagingManager* m_pMessagingManager = nullptr;

    private:
        void HandleSdlEvents();

        BlackBoxManager() = default;
        ~BlackBoxManager();
	public:
        BlackBoxManager(const BlackBoxManager&) = delete;
        BlackBoxManager(BlackBoxManager&&) = delete;
        void operator=(const BlackBoxManager&) = delete;
        void operator=(BlackBoxManager&&) = delete;

        const WindowPtr& GetWindow(size_t sceneIndex) { return m_scenes[sceneIndex]->m_pWindow; }
        const ScenePtr& GetScene(size_t index) { return m_scenes[index]; }
		[[nodiscard("index not caught after creating window")]] size_t CreateSceneWindow
			(const char* title, int xPos, int yPos, int width, int height);
		
		int StartEngine();
		int InitEngine();
        static BlackBoxManager* Get();
	};


}

