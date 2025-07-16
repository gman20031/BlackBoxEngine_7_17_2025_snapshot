#include "ResourceManager.h"

#include "../Graphics/Renderer.h"
#include "DataFactory.h"


namespace BlackBoxEngine
{
    inline TextureFactory* ResourceManager::GetTextureFactory()
    {
        static TextureFactory* pTexFactory = new TextureFactory;
        return pTexFactory;
    }
    inline XMLFactory* ResourceManager::GetXMLFactory()
    {
        static XMLFactory* pTexFactory = new XMLFactory;
        return pTexFactory;
    }
    std::shared_ptr<BB_Texture> ResourceManager::GetTexture(BB_Renderer* pRenderer, const char* pFilepath)
    {
        return GetTextureFactory()->Create(pRenderer, pFilepath);
    }
    ActorXMLParser ResourceManager::GetActorXMLData(const char* pFilePath)
    {

        return GetXMLFactory()->CreateActorFromFile(pFilePath);
    }

    LevelXMLParser ResourceManager::GetLevelXMLData(const char* pFilePath)
    {
        return GetXMLFactory()->CreateLevel(pFilePath);
    }

}

