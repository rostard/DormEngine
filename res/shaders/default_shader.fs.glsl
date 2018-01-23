#version 330 core
#include "lighting.fsh"

void main() {
    gl_FragColor = vec4(vec3(texture(material.diffuse, texCoords0).r) ,1.0);
//    gl_FragColor = vec4(texCoords0, 0.0, 1.0);
}
