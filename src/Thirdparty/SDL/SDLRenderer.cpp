#include <iostream>
#include "SDL.h"
#include "SDLRenderer.hpp"
#include "SDLSurface.hpp"

namespace Agrume {

SDLRenderer::SDLRenderer(): Renderer()
{
    singleton = this;
}

SDLRenderer::~SDLRenderer()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool SDLRenderer::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK) == -1) {
        std::cout << "SDL error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    return true;
}

void SDLRenderer::createWindow(const char* title, int width, int height)
{
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    m_window = SDL_CreateWindow(
        title,                             // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        width,                             // width, in pixels
        height,                            // height, in pixels
        window_flags                       // flags
    );

    
    if (m_window == NULL) {
        // In the case that the window could not be made...
        std::cout << "Could not create window:" << SDL_GetError() << std::endl;
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

}

void SDLRenderer::clear()
{
    SDL_RenderClear(m_renderer);
}

void SDLRenderer::render(Surface& surf)
{
    SDLSurface& sdlSurf = dynamic_cast<SDLSurface&>(surf);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, sdlSurf.m_surface);
    SDL_RenderCopy(m_renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(m_renderer);
}

}