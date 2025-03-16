#include "Texture.h"

#include <SDL.h>
#include <SDL_image.h>

#include "../System/Log.h"

BlackBoxEngine::BB_Texture::BB_Texture(SDL_Texture* pTexture)
	: m_pSdlTexture(pTexture)
{
	if (!m_pSdlTexture)
		Log("Texture not Found : "  __FUNCTION__);
}

BlackBoxEngine::BB_Texture::~BB_Texture()
{
	if(m_pSdlTexture)
		SDL_free(m_pSdlTexture);
}

bool BlackBoxEngine::BB_Texture::SetAlpha(uint8_t alpha)
{
	return SDL_SetTextureAlphaMod(m_pSdlTexture, alpha);
}

bool BlackBoxEngine::BB_Texture::SetColorMod(const ColorValue& colorMod)
{
	return SDL_SetTextureColorMod(m_pSdlTexture, colorMod.r, colorMod.g, colorMod.b);
}


