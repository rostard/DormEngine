#version 330 core
#include "lighting.fsh"

uniform PointLight pointLight;

void main() {
    vec3 totalColor = vec3(0, 0, 0);
    vec4 color = texture(material.diffuse, texCoords0);

//    vec3 normal = normalize(normal0);
    vec3 normal = texture(material.normalMap, texCoords0).rgb;
    normal = normalize(TBN * ((255.0 / 128.0) * normal - 1.0));;
    vec3 viewDir = normalize(viewPos - worldPos0);
    totalColor += CalcPointLight(pointLight, normal, viewDir, worldPos0);

    gl_FragColor = vec4(totalColor, 1.0) * color;
}
