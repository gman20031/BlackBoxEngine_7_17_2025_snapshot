#pragma once

#include <memory>

#include <unordered_map>

#include "Renderer.h"

namespace BlackBoxEngine
{
	/**
	 * @brief Pure static factory for BB_Textures, handles caching to stop
	 * duplication of image files.
	 */
	class BB_TextureFactory
	{
	// typdefs
		using HashType = uint32_t;
		using BB_RendererPtr = BB_Renderer*;

	private: // Variables
		inline static std::unordered_map<HashType, std::weak_ptr<BB_Texture> > m_sTextureCache;

	public: // Functions
		BB_TextureFactory() = delete;

		static std::shared_ptr<BB_Texture> Create(const BB_RendererPtr pRenderer, const char* imageFilePath);
	};

}