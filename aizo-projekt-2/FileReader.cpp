#include "FileReader.h"
#include <sstream>

GraphFromFile FileReader::read(const std::string& filename)
{
    GraphFromFile result;
    result.number_of_vertices = 0;
    result.number_of_edges = 0;
    result.edges = nullptr;
    std::ifstream input_file(filename);
    if (input_file.good()) {
        std::string line;
        // First line has to contain number of vertices and number of edges seperated by space
        std::getline(input_file, line);
        std::istringstream graph_data (line);
        graph_data >> result.number_of_vertices;
        graph_data >> result.number_of_edges;
        result.edges = new EdgeFromFile[result.number_of_edges];
        for (int i = 0; i < result.number_of_edges; i++)
        {
            if (std::getline(input_file, line)) {
                std::istringstream edge_data(line);
                edge_data >> result.edges[i].u;
                edge_data >> result.edges[i].v;
                edge_data >> result.edges[i].weight;
            }
        }
    }
    input_file.close();
    return result;
};