//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_MESHLOADER_H
#define DORMENGINE_MESHLOADER_H

#include <string>
#include "../Mesh.h"

class MeshLoader {
public:
    static Mesh Load(const std::string& filename);
};


#endif //DORMENGINE_MESHLOADER_H
