#include "Window.hpp"
#include <iostream>

namespace PhysEn {
namespace Plotter {

Window::Window(const unsigned int screenWidth, const unsigned int screenHeight)
		: screenWidth{screenWidth}, screenHeight{screenHeight}
{ }

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Window::Create() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cerr << "Could not initialize SDL: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	this->window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, windowFlag);
	if(! this->window){
		std::cerr << "Could not open window: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(this->window, -1, renderFlag);
	if(! renderer){
		std::cerr << "Could not create renderer: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Window::drawBackground() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);
}

} // namespace Plotter
} // namespace PhysEn
