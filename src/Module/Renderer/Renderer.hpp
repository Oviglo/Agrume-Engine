#pragma once
#include "Module/Renderer/Surface.hpp"

namespace Agrume {

class Renderer 
{
protected:

    static Renderer *singleton;
    
public:
    static Renderer *getSingleton();
    virtual bool init() = 0;
    virtual void createWindow(const char* title, int width, int height) = 0;
    virtual void clear() = 0;
    virtual void render(Surface& surf) = 0;

    Renderer();
    ~Renderer();
};

}