#include "TextureFactory.h"

#include <SDL.h>
#include <SDL_image.h>

#include "../System/StringHash.h"
#include "../System/Log.h"
#include "Renderer.h"

const BlackBoxEngine::BB_TextureFactory::TexturePtr&
	  BlackBoxEngine::BB_TextureFactory::Create(const RendererPtr& pRenderer, const char* imageFilePath)
{
	StringHash_t hash = StringHash(imageFilePath);
	
	// find if already in cache
	auto it = m_sTextureCache.find(hash);
	if (it != m_sTextureCache.end())
		return it->second;

	// create new texture
	SDL_Texture* pSdlTexture = IMG_LoadTexture(pRenderer->m_pSdlRenderer, imageFilePath);
	auto retPair = m_sTextureCache.emplace(
			std::pair( hash, std::make_unique<BB_Texture>(pSdlTexture)
		)
	);
	
	// log errors
	if (!retPair.second or !pSdlTexture)
		Log(SDL_GetError(), " texture file path : ", imageFilePath);
	else
		Log(imageFilePath, " imported properly");
	
	// return new or faulty
	return retPair.first->second;
}
