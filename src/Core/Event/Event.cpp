#include "Event.hpp"

namespace Agrume {

Event::Event()
{

}

Event::Event(EventType type, int key) : type(type), key(key) {

}

bool Event::quit()
{
    return false;
}
}