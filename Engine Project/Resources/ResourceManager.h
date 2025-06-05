#pragma once

#include <memory>

#include "TextureFactory.h"
#include "DataFactory.h" 

namespace BlackBoxEngine
{
    class ResourceManager
    {
        ResourceManager() = delete;

        inline static TextureFactory* GetTextureFactory();
        inline static XMLFactory* GetXMLFactory();
    public:
        static std::shared_ptr<BB_Texture> GetTexture(BB_Renderer* pRenderer, const char* pFilepath);
        static ActorXMLParser GetActorXMLData(const char* pFilePath);
        static LevelXMLParser GetLevelXMLData(const char* pFilePath);
    };



}