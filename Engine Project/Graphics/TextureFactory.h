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
		using StringHash_t = uint32_t;
		using TexturePtr = std::unique_ptr<BB_Texture>;
		using RendererPtr = std::unique_ptr<BB_Renderer>;

	private: // Variables
		inline static std::unordered_map<StringHash_t, TexturePtr> m_sTextureCache;

	public: // Functions
		BB_TextureFactory() = delete;

		static const TexturePtr& Create(const RendererPtr& pRenderer, const char* imageFilePath);
	};

}