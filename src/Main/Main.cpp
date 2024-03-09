#include <iostream>
#include "Core/Agrume.hpp"

using namespace Agrume;

int main(int argc, char *argv[])
{
    std::cout << "HELLO I'M AGRUME" << std::endl;

    if(!Agrume::Agrume::instance->init()) {
        return 1;
    }

    Agrume::Agrume::instance->run();

    return 0;
}