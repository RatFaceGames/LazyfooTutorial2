#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Function Defs.
void init(SDL_Window* &window, SDL_Surface* &screenSurface);
void loadMedia(SDL_Surface* &image);
void close(SDL_Window* &window, SDL_Surface* &screenSurface, SDL_Surface* &image);


int main(int argc, char *argv[]) {
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Surface* image = nullptr;

	init(window, screenSurface);
	loadMedia(image);
	SDL_BlitSurface(image, nullptr, screenSurface, nullptr);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	close(window, screenSurface, image);

	return 0;
}

void init(SDL_Window* &window, SDL_Surface* &screenSurface) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Init Failed, Error: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow("SDL Tut 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL Init Failed, Error: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
	screenSurface = SDL_GetWindowSurface(window);
	return;
}

void loadMedia(SDL_Surface* &image) {
	image = SDL_LoadBMP("./hello_world.bmp");
	if(image == nullptr) {
		std::cout << "SDL Load Failed, Error: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
	return;
}
void close(SDL_Window* &window, SDL_Surface* &screenSurface, SDL_Surface* &image) {
	SDL_FreeSurface(screenSurface);
	screenSurface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
	return;
}