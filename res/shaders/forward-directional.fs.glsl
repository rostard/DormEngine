#version 330 core
#include "lighting.fsh"

uniform DirectionalLight dirLight;
uniform sampler2D shadowMap;

#include "sampling.glh"

void main() {
    vec2 texCoords = GetParallaxCoords(material.dispMap, TBN, normalize(viewPos - worldPos0), texCoords0, material.dispMapScale, material.dispMapOffset);

    vec4 color = texture(material.diffuse, texCoords);

    vec3 normal = normalize(texture(material.normalMap, texCoords).rgb);
    normal = normalize(TBN * (255.0/128.0 * normal - 1.0));
    vec3 viewDir = normalize(viewPos - worldPos0);
    vec3 totalColor = CalcDirLight(dirLight, normal, viewDir);


    vec3 lightPos = (lightPos0.xyz / lightPos0.w);
    float shadow = float(texture(shadowMap, lightPos.xy).r > lightPos.z - 0.005);

    vec3 colorAmt = totalColor * shadow;

    gl_FragColor = vec4(colorAmt, 1.0) * color;


}
