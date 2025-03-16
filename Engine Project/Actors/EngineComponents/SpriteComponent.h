#pragma once

#include <memory>

#include "../../Graphics/Texture.h"
#include "../../Graphics/Renderer.h"
#include "../Component.h"

namespace BlackBoxEngine
{
	class SpriteComponent : public Component
	{
	public:
		ID_FROM_NAME("SpriteComponent");

	private:
		float m_width = 0;
		float m_height= 0;
		std::unique_ptr<BB_Texture> m_pTexture;
		BB_Renderer* m_pRenderer;

	public:
		SpriteComponent(Actor* pOwner);

		void SetTexture(const char* pTexturePath);
		void SetDimensions(const float width, const float height);
		const BB_Point GetDimensions() const { return { m_width, m_height }; }

		virtual void Render();
	};
}