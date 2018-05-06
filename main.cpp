#include <SDL.h>
#include <stdio.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

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

bool loadMedia(){
  //Load splash image
  gHelloWorld = SDL_LoadBMP("./Images/nicface.png");
  if (gHelloWorld == NULL){
    printf("Unable to load image %s! SDL Error: %s\n","./Images/nicface.png", SDL_GetError());
    return false;
  }
  return true;
}

int main(int argc, char* args[]){
  //Start SDL and create window
  if (!init()){
    printf("Failed to initialize!\n")
    return 1;
  }
  //Load media
  if (!loadMedia()){
    printf("Failed to load media!\n")
    return 1;
  }
  //Apply the image
  SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
  //Update the surface
  SDL_UpdateWindowSurface(gWindow);
  //Wait ten seconds
  SDL_Delay(10000);
  //Free resources and close SDL
  close();

  return 0;
}
