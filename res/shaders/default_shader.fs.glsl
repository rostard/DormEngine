#version 330 core
#include "lighting.fsh"

void main() {
    gl_FragColor = vec4(texture(material.diffuse, texCoords0).rgb ,1.0);
//    gl_FragColor = vec4(texCoords0, 0.0, 1.0);
}
