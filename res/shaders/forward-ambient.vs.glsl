#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texCoords;

out vec2 texCoords0;

uniform mat4 MVP;

void main() {
    texCoords0 = texCoords;
    gl_Position = MVP * vec4(pos, 1.0);
}
