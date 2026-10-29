//Context.h
//Author:maker

#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include "Window.h"

struct Context{

  SDL_GLContext context_raw;

  Context(NativeWindow* window){
    context_raw = SDL_GL_CreateContext(window->window_raw);
    if(!context_raw)
      std::cout<<"Couldn't create GL Context, ERROR: "<< SDL_GetError() <<std::endl;
    else
      std::cout<<"Created Context"<<std::endl;
  }
  ~Context(){
    if(context_raw)
      SDL_GL_DestroyContext(context_raw);
  }

};

inline Context* createContext(NativeWindow* window){
  return new Context(window);
}

inline void destroyContext(Context* context){
  delete context;
  std::cout<<"Deleted Context"<<std::endl;
}

inline void makeContextCurrent(NativeWindow* window , Context* context){
  SDL_GL_MakeCurrent(window->window_raw, context->context_raw);
}
