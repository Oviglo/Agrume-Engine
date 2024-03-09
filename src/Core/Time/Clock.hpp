#pragma once

namespace Agrume {

class Clock
{
public:
    static unsigned int getTicks();
    static void delay(unsigned int ms);
};

}