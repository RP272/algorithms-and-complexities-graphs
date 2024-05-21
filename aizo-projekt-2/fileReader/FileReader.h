#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>
#include <string>

struct EdgeFromFile
{
	int u;
	int v;
	int weight;
};

struct GraphFromFile
{
	int number_of_vertices;
	int number_of_edges;
	EdgeFromFile* edges;
};

class FileReader
{
public:
    static GraphFromFile read(const std::string& filename);
};

#endif