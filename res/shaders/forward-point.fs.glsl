#version 330 core
#include "lighting.fsh"

uniform PointLight pointLight;

#include "parallax.glh"

void main() {
    vec3 totalColor = vec3(0, 0, 0);

    vec2 texCoords = GetParallaxCoords(material.dispMap, TBN, normalize(viewPos - worldPos0), texCoords0, material.dispMapScale, material.dispMapOffset);
    vec4 color = texture(material.diffuse, texCoords);
//    vec3 normal = normalize(normal0);
    vec3 normal = texture(material.normalMap, texCoords).rgb;
    normal = normalize(TBN * ((255.0 / 128.0) * normal - 1.0));;
    vec3 viewDir = normalize(viewPos - worldPos0);
    totalColor += CalcPointLight(pointLight, normal, viewDir, worldPos0);

    gl_FragColor = vec4(totalColor, 1.0) * color;
}
