#pragma once

#include <memory>

struct SDL_Window;

namespace BlackBoxEngine
{
	class BB_Window
	{
		SDL_Window* m_pSdlWindow = nullptr;
		friend class BB_Renderer;

	private:
		std::unique_ptr<BB_Renderer> m_pRenderer;

		const char* m_pTitle = nullptr;
		int m_xPos = 0;
		int m_yPos = 0;
		int m_width = 100;
		int m_height = 100;

		int m_SdlErrorCode = 0;

		bool m_keepRunning = true;

	public:
		BB_Window(const char* title, int xPos, int yPos, int width, int height);
		~BB_Window();
		BB_Window(const BB_Window&) = delete;
		BB_Window& operator=(const BB_Window&) = delete;

		int SetTitle(const char* title);
		int SetDimensions(int width, int height);
		int SetPosition(int x, int y);

		const std::unique_ptr<BB_Renderer>& GetRenderer() const { return m_pRenderer; }

		int StartWindow();
		int StopWindow();
		bool IsRunning() const { return m_keepRunning; }
	};


}
