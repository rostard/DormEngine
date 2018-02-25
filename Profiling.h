//
// Created by rostard on 24.02.18.
//

#ifndef DORMENGINE_PROFILING_H
#define DORMENGINE_PROFILING_H

#include <string>

#define PROFILING_DISABLE_MESH_DRAWING 0
#define PROFILING_DISABLE_SHADING 0
#define PROFILING_SET_1x1_VIEWPORT 0
#define PROFILING_SET_2x2_TEXTURES 0

class ProfileTimer {
public:
    ProfileTimer() : numOfInvokations(0), totalTime(0), startTime(0) {}

    void startInvocation();
    void stopInvocation();
    double displayAndReset(const std::string &message, double inputDelimeter = 0);
    double getAndReset(double inputDelimeter = 0);
private:
    int numOfInvokations;
    double totalTime;
    double startTime;

};


#endif //DORMENGINE_PROFILING_H
