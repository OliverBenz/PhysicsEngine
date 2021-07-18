#pragma once

#include <SDL2/SDL.h>

namespace PhysEn {
namespace Plotter {

class Window{
public:
	Window(const unsigned int screenWidth, const unsigned int screenHeight);
	~Window();

	bool Create();
	void drawBackground();

private:
	const unsigned int screenWidth;
	const unsigned int screenHeight;

	const int renderFlag = SDL_RENDERER_ACCELERATED;
	const int windowFlag = 0;

	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
};

} // namespace Plotter
} // namespace PhysEn
