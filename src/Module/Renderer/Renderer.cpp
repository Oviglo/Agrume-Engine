#include "Renderer.hpp"

namespace Agrume {

Renderer *Renderer::singleton = nullptr;

Renderer * Renderer::getSingleton() {

    return singleton;
}

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{

}

}