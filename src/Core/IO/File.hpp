#pragma once
#include <fstream>
#include <iostream>
#include <string>

namespace Agrume {

class File
{
public:
    static File* ReadFile(std::string filename);
    static std::string getExtension(std::string filename);
    
    File(std::string fileName);
    ~File();
    int length();
    std::string type();
    std::string read(int length);
    std::string read();
    bool isOpen();

protected:

    std::ifstream m_file;
    std::string m_fileName;
    std::string m_type;
    bool m_isOpen;
    int m_length;
};

}