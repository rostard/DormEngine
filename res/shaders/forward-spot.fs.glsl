#version 330 core
#include "lighting.fsh"

uniform SpotLight spotLight;


void main() {
    vec3 totalColor = vec3(0, 0, 0);
    vec4 color = texture(material.diffuse, texCoords0);

//    vec3 normal = normalize(normal0);

    vec3 normal = normalize(texture(material.normalMap, texCoords0).rgb);
    normal = normalize(TBN * (2.0 * normal - 1.0));
    vec3 viewDir = normalize(viewPos - worldPos0);
    totalColor += CalcSpotLight(spotLight, normal, viewDir, worldPos0);

    gl_FragColor = vec4(totalColor, 1.0) * color;
}
