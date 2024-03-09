#pragma once

#include "Module/Renderer/Renderer.hpp"

namespace Agrume
{

class Agrume 
{
private:
    Renderer*   m_renderer;
    bool        m_isRunning;

public:
    Agrume();
    ~Agrume();
    bool init();
    void run();

    static Agrume* instance;
};

}