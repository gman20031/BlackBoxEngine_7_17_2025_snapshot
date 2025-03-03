#include "Texture.h"

#include <SDL.h>
#include <SDL_image.h>

#include "Window.h"
#include "Renderer.h"

#include "../Auxillary/Log.h"

BlackBoxEngine::BB_Texture::BB_Texture(SDL_Texture* pTexture)
	: m_pSdlTexture(pTexture)
{
	if (!m_pSdlTexture)
		Log("Texture not Found : "  __FUNCTION__);

}

int BlackBoxEngine::BB_Texture::Render()
{


	return 0;
}
