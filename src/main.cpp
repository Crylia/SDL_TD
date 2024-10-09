#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

int main( ) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError( ) << std::endl;
		return -1;
	}

	auto window = SDL_CreateWindow(
		"SDL_TD",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600,
		400,
		SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError( ) << std::endl;
		SDL_Quit( );
		return -1;
	}

	bool isRunning = true;
	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit( );
	return 0;
}
