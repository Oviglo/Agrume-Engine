#pragma once
#include "Module/Renderer/Surface.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include <string>

namespace Agrume {

class SDLRenderer;

class SDLSurface: public Surface 
{
    friend class SDLRenderer;
public:
    SDLSurface(int width = 32, int height = 32);
    SDLSurface(Sizes sizes);
    SDLSurface(const std::string& filename);

    void clear(Color color);
    void blit(Surface &dest, int x, int y);
    void blit(Surface &dest, int x, int y, int w, int h);
    void blit(Surface &dest, int x, int y, int w, int h, int sx, int sy);
    void blit(Surface &dest, int x, int y, int w, int h, int sx, int sy, int sw, int sh);

    // Drawing
    void drawRect(int x, int y, int w, int h, Color color);

    int w() const;
    int h() const;
    Sizes sizes() const;   

private:
    SDL_Surface* m_surface;
};

}