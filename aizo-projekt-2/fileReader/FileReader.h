#ifndef FILEREADER_H
#define FILEREADER_H
#include "GraphFromFile.h"
#include <string>

class FileReader
{
public:
    static GraphFromFile* read(const std::string& filename);
};

#endif