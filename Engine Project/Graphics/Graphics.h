#pragma once

#include "Color.h"
#include "Window.h"

struct SDL_Renderer;

namespace BlackBoxEngine
{
	struct BB_Point
	{
		float x;
		float y;
	};

	struct BB_Rectangle
	{
		float x;
		float y;
		float w;
		float h;
	};

	class BB_Renderer
	{
	private:
		SDL_Renderer* m_pSdlRenderer = nullptr;
	
		// default renderer background color
		ColorValue m_defaultBackgroundColor = ColorPresets::black;
		ColorValue m_defaultRenderColor = ColorPresets::white;

		// current draw color
		ColorValue m_currentDrawColor;

	public:

		BB_Renderer(BB_Window* pWindow);
		

		void ClearRenderer();
		void Present();

		// draw line
		void DrawLine(BB_Point start, BB_Point end);

		// draw rectangle
		void DrawRect(const BB_Rectangle& rec);
		void DrawRectFilled(const BB_Rectangle& rec);

		// draw texture
		// draw presetSprite
	};

	// class texture

	// struct Sprite
}