#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texCoords;
layout(location = 1) in vec3 normal;


out vec2 texCoords0;
out vec3 normal0;
out vec3 worldPos0;

uniform mat4 model;
uniform mat4 MVP;

void main() {
    texCoords0 = texCoords;
    normal0 = normal;
    worldPos0 = vec3(model * vec4(pos, 1.0));
    gl_Position = MVP * vec4(pos, 1.0);
}
