#include "TextureFactory.h"

#include <SDL.h>
#include <SDL_image.h>

#include "../System/StringHash.h"
#include "../System/Log.h"
#include "Renderer.h"

std::shared_ptr<BlackBoxEngine::BB_Texture>
BlackBoxEngine::BB_TextureFactory::Create(const BB_RendererPtr pRenderer, const char* imageFilePath)
{
	HashType hash = StringHash(imageFilePath);
	
	// find if already in cache
	auto it = m_sTextureCache.find(hash);
	if (it != m_sTextureCache.end())
        return it->second.lock();

	// create new texture
	SDL_Texture* pSdlTexture = IMG_LoadTexture(pRenderer->m_pSdlRenderer, imageFilePath);
    std::shared_ptr<BB_Texture> retVal = std::make_shared<BB_Texture>(pSdlTexture);
    auto retPair = m_sTextureCache.emplace(hash, retVal);
	
	// log errors
    if (!retPair.second or !pSdlTexture)
        BB_LOG(LogType::kError, SDL_GetError(), " texture file path : ", imageFilePath);
    else
        BB_LOG(LogType::kMessage, imageFilePath, " imported properly");
	
	// return new or faulty
    return retVal;
}
