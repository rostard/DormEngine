#version 330 core
#include "lighting.glh"


uniform sampler2D texture_diffuse;
uniform SpotLight spotLight;


in vec2 texCoords0;
in vec3 normal0;
in vec3 worldPos0;


void main() {
    vec3 totalColor = vec3(0, 0, 0);
    vec4 color = texture(texture_diffuse, texCoords0);

    vec3 normal = normalize(normal0);
    vec3 viewDir = normalize(viewPos - worldPos0);
    totalColor += CalcSpotLight(spotLight, normal, viewDir, worldPos0);

    gl_FragColor = vec4(totalColor, 1.0) * color;
}
