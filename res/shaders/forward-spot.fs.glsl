#version 330 core
#include "lighting.fsh"

uniform SpotLight spotLight;
uniform sampler2D shadowMap;

void main() {
    vec2 texCoords = GetParallaxCoords(material.dispMap, TBN, normalize(viewPos - worldPos0), texCoords0, material.dispMapScale, material.dispMapOffset);
    vec4 color = texture(material.diffuse, texCoords);

//    vec3 normal = normalize(normal0);

    vec3 normal = normalize(texture(material.normalMap, texCoords).rgb);
    normal = normalize(TBN * (2.0 * normal - 1.0));
    vec3 viewDir = normalize(viewPos - worldPos0);
    vec3 totalColor = CalcSpotLight(spotLight, normal, viewDir, worldPos0);

    vec3 lightPos = lightPos0.xyz / lightPos0.w;

    float shadow = sampleVarianceShadowMap(shadowMap, lightPos.xy, lightPos.z);
    vec3 colorAmt = totalColor * shadow;

    gl_FragColor = vec4(colorAmt, 1.0) * color;
}
