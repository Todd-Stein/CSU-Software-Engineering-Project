#include <iostream>

#include <SDL.h>

int main(int argc, char* [] argv) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Failed to initialize SDL" << std::endl;
		return EXIT_FAILURE;
	}
	SDL_Window* window = SDL_CreateWindow("Main Window", 640, 480, SDL_WINDOW_MAXIMIZED);

	SDL_ShowWindow(window);

	SDL_Event* evt;
	while (SDL_PollEvent(evt)) {
		std::cout << "window test" << std::endl;
	}
	return EXIT_SUCCESS
}