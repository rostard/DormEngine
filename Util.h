//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_UTIL_H
#define ENGINE_UTIL_H

#include <string>
#include <bits/ios_base.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Log.h"

namespace util{
    std::string loadStrFromFile(const std::string& filename){
        try {
            std::stringstream shaderStream;
            std::ifstream file;

            file.open("res/shaders/" + filename);

            if(!file.is_open()){
                Log::log("error loading file " + filename);
                exit(1);
            }

            shaderStream<<file.rdbuf();
            file.close();

            std::string ret = shaderStream.str();
            return shaderStream.str();
        }
        catch (std::exception e){
            e.what();
        }

    }

}

#endif //ENGINE_UTIL_H
