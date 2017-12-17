//
// Created by rostard on 14.12.17.
//

#include <iostream>
#include "Log.h"

void Log::log(const std::string &message) {
    std::cerr<<message<<std::endl;
}
