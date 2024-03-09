#pragma once

#include "Core/Event/Event.hpp"
#include <SDL.h>

namespace Agrume {


class SDLEvent: public Event 
{

public:
    SDLEvent(EventType type = EVENT_TYPE_KEYBOARD, int key = 0);

    static bool quit();
};
    
}