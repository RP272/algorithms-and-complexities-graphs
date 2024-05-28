#include "FileReader.h"
#include <sstream>
#include <fstream>

GraphFromFile* FileReader::read(const std::string& filename)
{
    GraphFromFile* result = new GraphFromFile();
    result->set_number_of_vertices(0);
    result->set_edge_collection(nullptr);
    int tmp, number_of_edges;
    Edge* edges;
    std::ifstream input_file(filename);
    if (input_file.good()) {
        std::string line;
        // First line has to contain number of vertices and number of edges seperated by space
        std::getline(input_file, line);
        std::istringstream graph_data (line);
        graph_data >> tmp;
        result->set_number_of_vertices(tmp);
        graph_data >> number_of_edges;
        edges = new Edge[number_of_edges];
        for (int i = 0; i < number_of_edges; i++)
        {
            if (std::getline(input_file, line)) {
                std::istringstream edge_data(line);
                edge_data >> tmp;
                edges[i].set_start_vertex_id(tmp);
                edge_data >> tmp;
                edges[i].set_end_vertex_id(tmp);
                edge_data >> tmp;
                edges[i].set_weight(tmp);
            }
        }
        result->set_edge_collection(new EdgeCollection(edges, number_of_edges));
    }
    input_file.close();
    return result;
};