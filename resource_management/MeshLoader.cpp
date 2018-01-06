//
// Created by rostard on 24.12.17.
//

#include "MeshLoader.h"
#include "../utility/Log.h"


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Mesh MeshLoader::Load(const std::string &filename) {
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile("res/models/"+filename, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        Log::log("ERROR::ASSIMP::" + std::string(import.GetErrorString()));
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    for(int i = 0; i < scene->mNumMeshes; i++){
        const aiMesh* paiMesh = scene->mMeshes[i];
        for(int j = 0; j< paiMesh->mNumFaces; j++){
            indices.push_back(paiMesh->mFaces[j].mIndices[0]);
            indices.push_back(paiMesh->mFaces[j].mIndices[1]);
            indices.push_back(paiMesh->mFaces[j].mIndices[2]);
        }

        for(int j = 0; j<paiMesh->mNumVertices;j++){
            const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

            const aiVector3D* pPos      = &(paiMesh->mVertices[j]);
            const aiVector3D* pNormal   = &(paiMesh->mNormals[j]);
            const aiVector3D* pTexCoord = paiMesh->HasTextureCoords(0) ? &(paiMesh->mTextureCoords[0][j]) : &Zero3D;
            const aiVector3D* pTangent  = paiMesh->HasTextureCoords(0) ? &(paiMesh->mTangents[j]) : &Zero3D;

            Vertex v(Vector3f(pPos->x, pPos->y, pPos->z), Vector2f(pTexCoord->x, pTexCoord->y),
                     Vector3f(pNormal->x, pNormal->y, pNormal->z), Vector3f(pTangent->x, pTangent->y, pTangent->z));

            vertices.push_back(v);
        }

    }

    return Mesh(vertices, indices);
}

