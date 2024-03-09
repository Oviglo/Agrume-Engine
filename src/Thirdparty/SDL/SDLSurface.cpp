#include "SDLSurface.hpp"
#include <iostream>

namespace Agrume {

SDLSurface::SDLSurface(int width, int height)
{
    Uint32 rmask, gmask, bmask, amask;
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
    #endif
    m_surface = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);
    if (m_surface == NULL ) {
        std::cout << "Unable create surface !" << std::endl;
    }
}

SDLSurface::SDLSurface(Sizes sizes) : SDLSurface(sizes.w, sizes.h)
{
}


SDLSurface::SDLSurface(const std::string& filename)
{
    m_surface = IMG_Load(filename.data()); 
    if (m_surface == NULL ) {
        std::cout << "SDL_image error: "<< IMG_GetError() << std::endl;
    }
}

void SDLSurface::clear(Color color)
{
    SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, color.r, color.g, color.b));
    SDL_SetSurfaceAlphaMod(m_surface, 255);
}

void SDLSurface::blit(Surface &dest, int x, int y)
{
    SDLSurface& surf = dynamic_cast<SDLSurface&>(dest);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_BlitSurface(m_surface, NULL, surf.m_surface, &rect);
}

void SDLSurface::blit(Surface &dest, int x, int y, int w, int h)
{
    SDLSurface& surf = dynamic_cast<SDLSurface&>(dest);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_BlitSurface(m_surface, NULL, surf.m_surface, &rect);
}

void SDLSurface::blit(Surface &dest, int x, int y, int w, int h, int sx, int sy)
{
    SDLSurface& surf = dynamic_cast<SDLSurface&>(dest);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_Rect sRect;
    sRect.x = sx;
    sRect.y = sy;

    SDL_BlitSurface(m_surface, &sRect, surf.m_surface, &rect);
}

void SDLSurface::blit(Surface &dest, int x, int y, int w, int h, int sx, int sy, int sw, int sh)
{
    SDLSurface& surf = dynamic_cast<SDLSurface&>(dest);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_Rect sRect;
    sRect.x = sx;
    sRect.y = sy;
    sRect.w = sw;
    sRect.h = sh;

    SDL_BlitSurface(m_surface, &sRect, surf.m_surface, &rect);   
}

void SDLSurface::drawRect(int x, int y, int w, int h, Color color)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_FillRect(m_surface, &rect, SDL_MapRGB(m_surface->format, color.r, color.g, color.b));
}

int SDLSurface::w() const
{
    return m_surface->w;
}

int SDLSurface::h() const
{
    return m_surface->h;
}

Sizes SDLSurface::sizes() const
{
    return Sizes(m_surface->w, m_surface->h);
}

}