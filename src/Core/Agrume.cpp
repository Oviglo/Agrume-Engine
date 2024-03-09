#include "Agrume.hpp"
#include "Thirdparty/SDL/SDLRenderer.hpp"
#include "Thirdparty/SDL/SDLEvent.hpp"

namespace Agrume {

Agrume* Agrume::instance = new Agrume();

Agrume::Agrume(): m_isRunning(true)
{
    m_renderer = new SDLRenderer();
}

Agrume::~Agrume()
{
    delete m_renderer;
}

bool Agrume::init()
{
    if (!m_renderer->init()) {
        return false;
    }

    // Create main window
    m_renderer->createWindow("Agrume", 800, 600);

    return true;
}

void Agrume::run()
{
    // Main loop
    while(m_isRunning)
    {
        m_isRunning = !SDLEvent::quit();
    }
}
}