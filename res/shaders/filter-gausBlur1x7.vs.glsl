#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoords;

uniform mat4 MVP;

out vec2 texCoords0;

void main() {
    gl_Position = MVP * vec4(pos, 1.0);
    texCoords0 = texCoords;
}
