#pragma once

#include "JsonFile.hpp"
#include "nlohmann/json.hpp"

using Json = nlohmann::json;

namespace Agrume {

class Resource
{
public:
    static Json getConfig();
};

}