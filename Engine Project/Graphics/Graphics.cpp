#include "Graphics.h"

#include <SDL.h>


BlackBoxEngine::BB_Renderer::BB_Renderer(BB_Window* pWindow)
{
	m_pSdlRenderer = SDL_CreateRenderer(pWindow->m_pSdlWindow, NULL);
}

void BlackBoxEngine::BB_Renderer::ClearRenderer()
{
	SDL_RenderClear(m_pSdlRenderer);
}

void BlackBoxEngine::BB_Renderer::Present()
{
	SDL_RenderPresent(m_pSdlRenderer);
}

void BlackBoxEngine::BB_Renderer::DrawLine(BB_Point start, BB_Point end)
{
	SDL_RenderLine(m_pSdlRenderer, start.x, start.y, end.x, end.y);
}

void BlackBoxEngine::BB_Renderer::DrawRect(const BB_Rectangle& rec)
{
	SDL_FRect sdlRect{ rec.x, rec.y , rec.w, rec.h };
	SDL_RenderRect(m_pSdlRenderer, &sdlRect);
}

void BlackBoxEngine::BB_Renderer::DrawRectFilled(const BB_Rectangle& rec)
{
	SDL_FRect sdlRect{ rec.x, rec.y , rec.w, rec.h };
	SDL_RenderFillRect(m_pSdlRenderer, &sdlRect);
}
