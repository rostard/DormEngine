//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_LOG_H
#define ENGINE_LOG_H

#include <string>

class Log {
public:
    Log() = delete;

    static void log(const std::string& message);
};


#endif //ENGINE_LOG_H
