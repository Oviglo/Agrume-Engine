#pragma once

#include "SDL.h"
#include "Module/Renderer/Renderer.hpp"

namespace Agrume {

class SDLRenderer: public Renderer {

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

public:
    bool init();
    void createWindow(const char* title, int width, int height);

    SDLRenderer();
    ~SDLRenderer();
};

}