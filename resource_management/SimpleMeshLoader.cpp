//
// Created by rostard on 20.12.17.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include "SimpleMeshLoader.h"
#include "../utility/Log.h"

Mesh SimpleMeshLoader::loadMesh(const std::string& filename) {
    if(filename.substr(filename.find_last_of('.'))!=".obj"){
        Log::log("Mesh Loader cannot open format " + filename.substr(filename.find_last_of('.')));
        return Mesh();
    }

    std::ifstream ifstream("res/models/"+filename);

    if(!ifstream.is_open()){
        Log::log("error loading file " + filename);
        exit(1);
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    while(!ifstream.eof()){
        std::vector<std::string> tokens;
        std::string line, word;
        std::getline(ifstream, line);
        std::stringstream ss(line);
        while(std::getline(ss, word, ' ')){
            word = word.substr(0, word.find_first_of('/'));
            tokens.push_back(word);
        }
        if(line.empty())continue;
        if(tokens[0] == "v")vertices.push_back(Vertex(Vector3f(std::atof(tokens[1].c_str()), std::atof(tokens[2].c_str()), std::atof(tokens[3].c_str()))));
        if(tokens[0] == "f") {
            indices.push_back(std::atoi(tokens[1].c_str())-1);
            indices.push_back(std::atoi(tokens[2].c_str())-1);
            indices.push_back(std::atoi(tokens[3].c_str())-1);
        }

        std::atoi(tokens[1].c_str());
    }
    ifstream.close();

    return  Mesh(vertices, indices);
}
