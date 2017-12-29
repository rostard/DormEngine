#version 330 core
#include "lighting.glh"

in vec2 texCoords0;

uniform vec3 ambientLight;

void main(){
    gl_FragColor = texture2D(material.diffuse, texCoords0) * vec4(ambientLight, 1.0);
}