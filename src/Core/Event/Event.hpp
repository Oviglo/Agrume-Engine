#pragma once

namespace Agrume {
typedef enum {
    EVENT_TYPE_KEYBOARD = 1,
    EVENT_TYPE_MOUSE = 2,
    EVENT_TYPE_JOYSTICK = 3

} EventType;

class Event 
{

private:

public:
    Event();
    Event(EventType type, int key);

    static bool quit();

    EventType type;
    int key;
};
}