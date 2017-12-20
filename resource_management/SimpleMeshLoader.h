//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_SIMPLEMESHLOADER_H
#define DORMENGINE_SIMPLEMESHLOADER_H

#include <string>
#include "../Mesh.h"

class SimpleMeshLoader {
public:
    static Mesh loadMesh(const std::string& filename);
};


#endif //DORMENGINE_SIMPLEMESHLOADER_H
