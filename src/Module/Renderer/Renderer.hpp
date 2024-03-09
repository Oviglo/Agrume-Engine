#pragma once

namespace Agrume {

class Renderer 
{
protected:

    static Renderer *singleton;
    
public:
    static Renderer *getSingleton();
    virtual bool init() = 0;
    virtual void createWindow(const char* title, int width, int height) = 0;

    Renderer();
    ~Renderer();
};

}