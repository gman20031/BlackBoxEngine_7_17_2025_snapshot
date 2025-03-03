#include "Window.h"

#include "../Auxillary/Log.h"
#include "SDL.h"
#include "Renderer.h"

BlackBoxEngine::BB_Window::BB_Window(const char* title, int xPos, int yPos, int width, int height)
	: m_pTitle(title)
	, m_xPos(xPos)
	, m_yPos(yPos)
	, m_width(width)
	, m_height(height)
{

}

BlackBoxEngine::BB_Window::~BB_Window()
{
	SDL_free(m_pSdlWindow);
}

int BlackBoxEngine::BB_Window::SetTitle(const char* title)
{
	if (!SDL_SetWindowTitle(m_pSdlWindow, title))
	{
		Log(SDL_GetError());
		return 1;
	}
	m_pTitle = title;
	return 0;
}

int BlackBoxEngine::BB_Window::SetDimensions(int width, int height)
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

int BlackBoxEngine::BB_Window::SetPosition(int x, int y)
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

int BlackBoxEngine::BB_Window::StartWindow()
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

	m_pRenderer = std::make_unique<BB_Renderer>(this);
	if (!m_pRenderer)
	{
		Log("Renderer not Created");
		return 1;
	}

	return 0;
}

int BlackBoxEngine::BB_Window::StopWindow()
{
	m_keepRunning = false;
    return 0;
}
