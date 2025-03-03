#pragma once

#include <memory>

#include "Texture.h"

namespace BlackBoxEngine
{

	/**
	 * @brief Pure static factory for BB_Textures, handles caching to stop
	 * duplication of image files.
	 */
	class BB_TextureFactory
	{
	public: // typdefs
		using TexturePtr = std::unique_ptr<BB_Texture>;

	private: // Variables


	public: // Functions
		BB_TextureFactory() = delete;


		

	};

}