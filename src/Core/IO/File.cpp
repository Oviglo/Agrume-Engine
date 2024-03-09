#include "File.hpp"
#include "JsonFile.hpp"

namespace Agrume {

std::string File::getExtension(std::string filename)
{
    return std::string(filename.substr(filename.find_last_of(".") + 1));
}

File* File::ReadFile(std::string filename)
{
    std::string ext = File::getExtension(filename);

    if (ext == "json")
    {
        return new JsonFile(filename); 
    }

    return new File(filename);
}

File::File(std::string fileName) : m_fileName(fileName), m_isOpen(false) {
    m_file.open(fileName.c_str());

    if (m_file) {
        m_isOpen = true;

        m_file.seekg(0, m_file.end);
        m_length = m_file.tellg();
        m_file.seekg(0, m_file.beg);

        m_type = "Unknown";
    }
}

File::~File() {
    m_file.close();
}

std::string File::read(int length) {
    char* buffer = new char[length];
    m_file.read(buffer, length);

    std::string str(buffer);
    delete[] buffer;

    return str;
}

std::string File::read() {
    return read(m_length);
}

bool File::isOpen() {
    return m_isOpen;
}

std::string File::type() {
    return m_type;
}

int File::length() {
    return m_length;
}

}