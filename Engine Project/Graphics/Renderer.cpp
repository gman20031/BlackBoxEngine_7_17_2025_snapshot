#include "Renderer.h"

#include <SDL.h>
#include <assert.h>

#include "../System/Log.h"

//////////////////////////////////////////////////////////////////
///  Private Functions
//////////////////////////////////////////////////////////////////

/**
 * @brief Calls SDL_SetRenderDrawColor() with the inputed colorvalue
 * @param newColor 
 * @return Forwards return of SDL_SetRenderDrawColor()
 */
bool BlackBoxEngine::BB_Renderer::SetSDLDrawColor(const ColorValue& newColor)
{
	return SDL_SetRenderDrawColor(m_pSdlRenderer,
		newColor.r, newColor.g, newColor.b, newColor.a);
}

//////////////////////////////////////////////////////////////////
///  Public Functions
//////////////////////////////////////////////////////////////////

BlackBoxEngine::BB_Renderer::BB_Renderer(BB_Window* pWindow)	
	: m_pAttachedWindow(pWindow)
	, m_currentBackgroundColor(kDefaultBackgroundColor)
	, m_currentDrawColor(kDefaultDrawColor)
{
	assert(pWindow);

	m_pSdlRenderer = SDL_CreateRenderer(pWindow->m_pSdlWindow, NULL);
	if (!m_pSdlRenderer)
		SimpleLog(SDL_GetError());

	SetRenderDrawColor(kDefaultDrawColor);
}

BlackBoxEngine::BB_Renderer::~BB_Renderer()
{
	if (m_pSdlRenderer)
		SDL_free(m_pSdlRenderer);
}

/**
 * @brief Sets the draw color to background color, and fills the screen with that color.
 * Then swaps back to the normal set draw color.
 */
void BlackBoxEngine::BB_Renderer::ClearRenderer()
{
	SetSDLDrawColor(m_currentBackgroundColor);
	SDL_RenderClear(m_pSdlRenderer);
	SetSDLDrawColor(m_currentDrawColor);
}

void BlackBoxEngine::BB_Renderer::Present()
{
	if (!SDL_RenderPresent(m_pSdlRenderer))
        SimpleLog(SDL_GetError());
}

bool BlackBoxEngine::BB_Renderer::SetRenderDrawColor(const ColorValue& newDrawColor)
{
	m_currentDrawColor = newDrawColor;
	return SetSDLDrawColor(newDrawColor);
}

bool BlackBoxEngine::BB_Renderer::SetRenderBackgroundColor(const ColorValue& newBackgroundColor)
{
	m_currentBackgroundColor = newBackgroundColor;
	return true;
}

bool BlackBoxEngine::BB_Renderer::DrawLine(BB_Point start, BB_Point end)
{
	return SDL_RenderLine(m_pSdlRenderer, start.x, start.y, end.x, end.y);
}

bool BlackBoxEngine::BB_Renderer::DrawRect(const BB_Rectangle& rec)
{
	SDL_FRect sdlRect{ rec.x, rec.y , rec.w, rec.h };
	return SDL_RenderRect(m_pSdlRenderer, &sdlRect);
}

bool BlackBoxEngine::BB_Renderer::DrawRectFilled(const BB_Rectangle& rec)
{
	SDL_FRect sdlRect{ rec.x, rec.y , rec.w, rec.h };
	return SDL_RenderFillRect(m_pSdlRenderer, &sdlRect);
}

const char* BlackBoxEngine::BB_Renderer::GetErrorStr()
{
	return SDL_GetError();
}

bool BlackBoxEngine::BB_Renderer::DrawTexture(
    BB_Texture* texture,
    const BB_Rectangle* source,
    const BB_Rectangle* dest,
    const double rot,
    const BB_Point* center,
    const BB_FlipVal& flip
)
{
    const SDL_FRect* pSdlSource = (const SDL_FRect*)(source);
    const SDL_FRect* pSdlDest = (const SDL_FRect*)(dest);
    const SDL_FPoint* pSdlCenter = (const SDL_FPoint*)(center);
    const SDL_FlipMode sdlFlip = static_cast<SDL_FlipMode>(flip);

    assert(m_pSdlRenderer);

    return SDL_RenderTextureRotated(
        m_pSdlRenderer,
        texture->m_pSdlTexture,
        pSdlSource,
        pSdlDest,
        rot,
        pSdlCenter,
        sdlFlip
    );

}
