//
// Created by rostard on 24.02.18.
//

#include <cassert>
#include "Profiling.h"
#include "Time.h"
#include "utility/Log.h"

void ProfileTimer::startInvocation() {
    startTime = Time::GetTime();
}

void ProfileTimer::stopInvocation(){
    if(startTime == 0){
        Log::Message("StopInvocation called without matching startInvocation", LOG_ERROR);
        assert(false);
    }

    ++numOfInvokations;
    totalTime += Time::GetTime() - startTime;
    startTime = 0;
}

double ProfileTimer::displayAndReset(const std::string &message, double inputDelimeter) {
    double time = getAndReset(inputDelimeter);
    Log::Message(message + std::to_string(time) + "ms", LOG_INFO);
    return time;
}

double ProfileTimer::getAndReset(double inputDelimeter) {
    double delimeter = inputDelimeter == 0 ? numOfInvokations : inputDelimeter;
    double time = 1000.0 * totalTime / delimeter;
    totalTime = 0;
    numOfInvokations = 0;
    return time;
}

