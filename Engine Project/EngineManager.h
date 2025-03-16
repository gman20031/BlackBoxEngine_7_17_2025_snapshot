#pragma once

#include <vector>
#include <memory>
#include <functional>

#include "Graphics/Window.h"
#include "Graphics/Renderer.h"

namespace BlackBoxEngine
{
	class BlackBoxManager
	{
	public:
		using WindowPtr = std::unique_ptr<BB_Window>;

	private:
		// Actor Manager
		 
		// Input Manager

		// Scene Manager
		std::vector< WindowPtr > m_allWindows;
		/* Scene manager
		*  	- Contains a number of scenes, each scene had 
		*/

	public:
		bool m_keepRunning = false;

	public:
		const WindowPtr& GetWindow(size_t index) { return m_allWindows[index]; };
		[[nodiscard("index not caught after creating window")]] size_t CreateNewWindow
			(const char* title, int xPos, int yPos, int width, int height);
		
		int StartEngine();
		int InitEngine();
	};


}

