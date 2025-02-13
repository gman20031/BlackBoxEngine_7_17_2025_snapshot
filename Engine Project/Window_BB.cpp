#include "Window_BB.h"

#include "Auxillary/Log.h"
#include "SDL.h"

BlackBoxEngine::GameWindow::GameWindow(const char* title, int xPos, int yPos, int width, int height)
	: m_pTitle(title)
	, m_xPos(xPos)
	, m_yPos(yPos)
	, m_width(width)
	, m_height(height)
{

}

BlackBoxEngine::GameWindow::~GameWindow()
{
	SDL_free(m_pSdlWindow);
}

int BlackBoxEngine::GameWindow::SetTitle(const char* title)
{
	if (!SDL_SetWindowTitle(m_pSdlWindow, title))
	{
		Log(SDL_GetError());
		return 1;
	}
	m_pTitle = title;
	return 0;
}

int BlackBoxEngine::GameWindow::SetDimensions(int width, int height)
{
	if (!SDL_SetWindowSize(m_pSdlWindow, width, height))
	{
		Log(SDL_GetError());
		return 1;
	}
	m_width = width;
	m_height = height;
	return 0;
}

int BlackBoxEngine::GameWindow::SetPosition(int x, int y)
{
	if (!SDL_SetWindowPosition(m_pSdlWindow, x, y))
	{
		Log(SDL_GetError());
		return 1;
	}
	m_width = x;
	m_height = y;
	return 0;
}

int BlackBoxEngine::GameWindow::StartWindow()
{

	m_pSdlWindow = SDL_CreateWindow(m_pTitle, m_width, m_height, 0);
	if (!m_pSdlWindow)
	{
		Log(SDL_GetError());
		return 1;
	}

	if (!SDL_SetWindowPosition(m_pSdlWindow, m_xPos, m_yPos))
	{
		Log(SDL_GetError());
		return 1;
	}

	SDL_Event event;
	while (m_keepRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_X)
				m_keepRunning = false;
			if (event.type == SDL_EVENT_QUIT)
				m_keepRunning = false;
		}
	}

	return 0;
}

int BlackBoxEngine::GameWindow::StopWindow()
{
	m_keepRunning = false;
    return 0;
}
