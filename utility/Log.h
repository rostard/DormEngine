//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_LOG_H
#define ENGINE_LOG_H


#include <map>
#include <iostream>
#include <string>

enum LOG_TYPE{
    LOG_INFO = 0,
    LOG_WARNING,
    LOG_ERROR
};

class Log {
public:
    static void Message(std::string message, LOG_TYPE type)
    {
        if(type >= filter){
            std::cerr<<type<<": "<<message<<std::endl;
        }
    }
    static void SetFilter(LOG_TYPE filter){
        Log::filter = filter;
    }
private:
    static LOG_TYPE filter;
};


#endif //ENGINE_LOG_H
