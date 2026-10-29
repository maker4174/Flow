//Window.h
//Author:maker

#pragma once

#include <SDL3/SDL.h>

#include <iostream>
#include <memory>

struct NativeWindow{

  SDL_WindowFlags FLAGS = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

  int width , height ;
  const char* title;

  SDL_Window* window_raw = nullptr;

  NativeWindow(const int width ,const int height, const char* title):

    width(width) , height(height) , title(title){

    this->window_raw = SDL_CreateWindow(title, width, height, FLAGS);
    if(!this->window_raw)
      std::cout<<"Failed to create window , ERROR :" << SDL_GetError()<<std::endl;
    else
      std::cout<<"Created Window"<<std::endl;
  }

  ~NativeWindow(){
    if(window_raw)
      SDL_DestroyWindow(window_raw);
    std::cout<<"Deleted Window"<<std::endl;
  }

  void set_windowPos(const int pos_x , const int pos_y){
    SDL_SetWindowPosition(this->window_raw, pos_x, pos_y);
  }
  void swap_window(){
    SDL_GL_SwapWindow(this->window_raw);
  }
  void show_win(){
    SDL_ShowWindow(this->window_raw);
  }
};

inline NativeWindow* createWindow(const int width , const int height , const char* name){
  return new NativeWindow(width , height , name);
}

inline void destroyWindow(NativeWindow* win){
  delete win;
}

inline void setWindowPos(NativeWindow* win, int pos_x , int pos_y){
  win->set_windowPos(pos_x, pos_y);
}

inline void swapWindow(NativeWindow* win){
  win->swap_window();
}

inline void showWindow(NativeWindow* win){
  win->show_win();
}

