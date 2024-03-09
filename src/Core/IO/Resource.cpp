#include "Resource.hpp"
#include "File.hpp"
#include <iostream>
#include <string>

namespace Agrume {

Json Resource::getConfig()
{
    std::string path = "./data/config.json";

    File* file = File::ReadFile(path);

    if (!file->isOpen()) {
        return 0;
    }

    if (file->type() != "Json") {
        std::cout << "Wrong config file format" << std::endl;
    }

    Json json = static_cast<JsonFile*>(file)->getJson();
    delete file;

    return json;
}
}