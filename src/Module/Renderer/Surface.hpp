#pragma once
#include "Core/Sizes.hpp"
#include "Core/Color.hpp"
#include <string>

namespace Agrume {

class Surface
{
public:
    static Surface* createSurface(int width, int height);
    static Surface* createSurface(Sizes sizes);
    static Surface* createSurface(const std::string& filename);

    Surface();
    Surface(int width, int height);
    Surface(Sizes $sizes);
    Surface(const std::string& filename);

    virtual void clear(Color color) = 0;
    // Blitting
    virtual void blit(Surface &dest, int x, int y) = 0;
    virtual void blit(Surface &dest, int x, int y, int w, int h) = 0;
    virtual void blit(Surface &dest, int x, int y, int w, int h, int sx, int sy) = 0;
    virtual void blit(Surface &dest, int x, int y, int w, int h, int sx, int sy, int sw, int sh) = 0;

    // Drawing
    virtual void drawRect(int x, int y, int w, int h, Color color) = 0;


    virtual int w() const = 0;
    virtual int h() const = 0;
    virtual Sizes sizes() const = 0;

protected:


};

}