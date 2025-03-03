#pragma once

struct SDL_Texture;
class BB_Renderer;
#include "RenderingStructs.h"

namespace BlackBoxEngine
{
	/**
	 * @brief Reprsentation of a image file within the engine.
	 */
	class BB_Texture
	{
		friend class BB_Renderer;
		SDL_Texture* m_pSdlTexture = nullptr;
	public:
		BB_Texture(SDL_Texture* pTexture);

		int Render();

	};


}