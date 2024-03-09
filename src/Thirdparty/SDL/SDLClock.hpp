#pragma once

#include "Core/Time/Clock.hpp"

namespace Agrume
{

class SDLClock: public Clock
{
public:
    static unsigned int getTicks();
    static void delay(unsigned int ms);
};

}