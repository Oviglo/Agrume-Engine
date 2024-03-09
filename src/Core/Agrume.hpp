#pragma once

#include "Module/Renderer/Renderer.hpp"
#include "nlohmann/json.hpp"

using Json = nlohmann::json;

namespace Agrume
{

class Agrume 
{
private:
    Renderer*   m_renderer;
    bool        m_isRunning;
    Json        m_mainConfig;


public:
    Agrume();
    ~Agrume();
    bool init();
    void run();

    static Agrume*  instance;
};

}