#pragma once

namespace Agrume {

class Color
{
public:
    short r;
    short g;
    short b;
    short a;

    Color(): r(0), g(0), b(0), a(0)
    {

    }

    Color(short r, short g, short b): r(r), g(g), b(b), a(0)
    {

    }

    static Color fromValue(unsigned int color)
    {
        Color c;
        c.r = (color & 0xff0000) >> 16;
        c.g = (color & 0x00ff00) >> 8;
        c.b = (color & 0x0000ff);

        return c;
    }
};

}