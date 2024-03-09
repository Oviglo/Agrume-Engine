#include "Surface.hpp"
#include "Thirdparty/SDL/SDLSurface.hpp"
#include <iostream>

namespace Agrume {

Surface::Surface()
{

}

Surface::Surface(int width, int height)
{

}

Surface::Surface(Sizes $sizes)
{

}
    
Surface::Surface(const std::string& filename)
{

}

Surface* Surface::createSurface(int width, int height)
{
    return new SDLSurface(width, height);
}

Surface* Surface::createSurface(Sizes sizes)
{
    return new SDLSurface(sizes);
}

Surface* Surface::createSurface(const std::string& filename)
{
    return new SDLSurface(filename);
}

}