#include "SDLClock.hpp"
#include "SDL.h"

namespace Agrume {

unsigned int SDLClock::getTicks()
{
    return SDL_GetTicks();
}

void SDLClock::delay(unsigned int ms)
{
    SDL_Delay(ms);
}

}