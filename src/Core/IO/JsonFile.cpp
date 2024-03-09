#include "JsonFile.hpp"

namespace Agrume {

JsonFile::JsonFile(std::string filename) : File(filename)
{
	m_type = "Json";
}

Json JsonFile::getJson()
{
	return Json::parse(m_file); 
}

}