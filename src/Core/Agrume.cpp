#include "Agrume.hpp"
#include "Thirdparty/SDL/SDLRenderer.hpp"
#include "Core/IO/Resource.hpp"
#include "Module/Renderer/Surface.hpp"
#include "Core/Color.hpp"

#if TIME_LIB == SDL
#include "Thirdparty/SDL/SDLClock.hpp"
using Clock = Agrume::SDLClock;
#endif

#if EVENT_LIB == SDL
#include "Thirdparty/SDL/SDLEvent.hpp"
using Event = Agrume::SDLEvent;
#endif

namespace Agrume {

Agrume* Agrume::instance = new Agrume();

Agrume::Agrume(): m_isRunning(true), m_mainConfig(0)
{
    #if RENDERER_LIB == SDL
    m_renderer = new SDLRenderer();
    #endif
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

    // Load main config file
    m_mainConfig = Resource::getConfig();
    if (m_mainConfig == 0) {
        fprintf(stderr, "Error: game file not found");

        return false;
    }

    // Create main window
    m_renderer->createWindow(
        m_mainConfig["name"].get<std::string>().data(),
        m_mainConfig["mainWindow"]["width"].get<int>(),
        m_mainConfig["mainWindow"]["height"].get<int>()
    );

    return true;
}

void Agrume::run()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    unsigned int frameStart;
    int frameTime;

    // Main loop
    while(m_isRunning)
    {
        frameStart = ::Clock::getTicks();
        m_isRunning = !::Event::quit();

        // Draw
        m_renderer->clear();
        Surface& surf = *Surface::createSurface(m_mainConfig["mainWindow"]["width"].get<int>(), m_mainConfig["mainWindow"]["height"].get<int>());
        surf.drawRect(20, 20, 300, 300, Color(0.2f, 0.5f, 1.0f));
        m_renderer->render(surf);

        frameTime = ::Clock::getTicks() - frameStart;

        if (frameDelay > frameTime) {
            ::Clock::delay(frameDelay - frameTime);
        }
    }
}
}