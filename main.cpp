#include <SDL.h>
#include <stdio.h>

bool init(){
  //Initialization flag
  bool success = true;
  //Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO)<0){
    printf("SDL could not initialize! SDL_Error:%s\n", SDL_GetError());
    return false;
  }
  //Create window
  gWindow = SDL_CreateWindow("SDLTutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
  if (gWindow == NULL){
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }
  //Get widnow SDL_Surface
  gScreenSurface = SDL_GetWindowSurface(gWindow);
}

void close(){
  //Deallocate surface
  SDL_FreeSurface(gHelloWorld);
  gHelloWorld=NULL;
  //Destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  //Quit SDL subsystems
  SDL_Quit();
}
