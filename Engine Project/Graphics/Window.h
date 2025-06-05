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
		BB_Renderer* m_pRenderer = nullptr;

		const char* m_pTitle = nullptr;
		int m_xPos = 0;
		int m_yPos = 0;
		int m_width = 100;
		int m_height = 100;

		int m_SdlErrorCode = 0;

		bool m_isOpen = true;

	public:
		BB_Window(const char* title, int xPos, int yPos, int width, int height);
		~BB_Window();
		BB_Window(const BB_Window&) = delete;
		BB_Window& operator=(const BB_Window&) = delete;

		int SetTitle(const char* title);
        int SetDimensions(int width, int height);
        int SetPosition(int x, int y);
        
        const char* GetTitle() const { return m_pTitle; }
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }
        int GetXPos() const { return m_xPos; }
        int GetYPos() const { return m_xPos; }

		BB_Renderer* const GetRenderer() const { return m_pRenderer; }

		int StartWindow();
		int StopWindow();
		bool IsOpen() const { return m_isOpen; }
	};


}
