#pragma once
#include "File.hpp"
#include <string>
#include "nlohmann/json.hpp"

using Json = nlohmann::json;

namespace Agrume {

class JsonFile: public File
{

public:
	JsonFile(std::string filename);
	Json getJson();
};

}