#version 330 core
#include "lighting.glh"

in vec2 texCoords0;
in vec3 normal0;
in vec3 worldPos0;

uniform PointLight pointLight;

void main() {
    vec3 totalColor = vec3(0, 0, 0);
    vec4 color = texture(material.diffuse, texCoords0);

    vec3 normal = normalize(normal0);
    vec3 viewDir = normalize(viewPos - worldPos0);
    totalColor += CalcPointLight(pointLight, normal, viewDir, worldPos0);

    gl_FragColor = vec4(totalColor, 1.0) * color;
}
