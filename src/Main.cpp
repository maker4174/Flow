//Main.cpp
//Author:maker

#include <glad/glad.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_main.h>
#include "Context.h"

#include <iostream>

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

int main (int argc, char *argv[]) {

  if(!SDL_Init(SDL_INIT_VIDEO)){
    std::cout<<"Failed to initialise SDL, ERROR: "<< SDL_GetError() <<std::endl;
    return -1;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  NativeWindow* window = createWindow(800 , 600 , "Flow");
  if(!window)
    return -1;

  Context* context = createContext(window);
  if(!context)
    return -1;

  makeContextCurrent(window, context);

  SDL_GL_SetSwapInterval(1);

  setWindowPos(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
  showWindow(window);

  if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)){
    std::cout<<"Failed to load GLAD"<<std::endl;
    return -1;
  }

  glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

  bool running = true;
  SDL_Event event;
  while(running){
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_EVENT_KEY_DOWN){
        if(event.key.key == SDLK_ESCAPE)
          running = false;
      }
      else if(event.type == SDL_EVENT_QUIT){
        running = false;
      }
      if (event.type == SDL_EVENT_WINDOW_RESIZED) {
        WINDOW_WIDTH = event.window.data1;
        WINDOW_HEIGHT = event.window.data2;
        glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
      }
    }

    glClearColor(0.0174f,0.0174f,0.0174f,1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    swapWindow(window);
    SDL_Delay(1);

  }
  destroyWindow(window);
  destroyContext(context);
  SDL_Quit();

  return 0;
}
