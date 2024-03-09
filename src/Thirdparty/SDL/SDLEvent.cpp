#include "SDLEvent.hpp"

namespace Agrume {

SDLEvent::SDLEvent(EventType type, int key) : Event(type, key) {
}

bool SDLEvent::quit()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    return event.type == SDL_QUIT;
}
}