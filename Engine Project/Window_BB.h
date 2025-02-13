#pragma once

class SDL_Window;

namespace BlackBoxEngine
{

	class GameWindow
	{
		SDL_Window* m_pSdlWindow = nullptr;

		const char* m_pTitle = nullptr;
		int m_xPos = 0;
		int m_yPos = 0;
		int m_width = 100;
		int m_height = 100;

		int m_SdlErrorCode = 0;

		bool m_keepRunning = true;

	public:
		GameWindow(const char* title, int xPos, int yPos, int width, int height);
		~GameWindow();
		GameWindow(const GameWindow&) = delete;
		GameWindow& operator=(const GameWindow&) = delete;

		int SetTitle(const char* title);
		int SetDimensions(int width, int height);
		int SetPosition(int x, int y);

		int StartWindow();
		int StopWindow();
	};


}
