#version 330 core

in vec2 texCoords0;



struct Material{
    sampler2D sourceTexture1;
    sampler2D sourceTexture2;
};

uniform vec3 blurScale;
uniform Material material;
uniform float exposure;

void main() {
    const float gamma = 2.2;
    vec3 color1 = texture(material.sourceTexture1, texCoords0).rgb;
    vec3 color2 = texture(material.sourceTexture2, texCoords0).rgb;
    vec3 hdrColor = color1 + color2;

    // Exposure tone mapping
    vec3 mapped = vec3(1.0) - exp(-hdrColor * exposure);
    // gamma correction
    mapped = pow(mapped, vec3(1.0 / gamma));

    gl_FragColor = vec4(mapped, 1.0);

}
