#version 330 core

in vec2 texCoords0;



struct Material{
    sampler2D sourceTexture;
};

uniform vec3 blurScale;
uniform Material material;
uniform float exposure;

void main() {
    const float gamma = 2.2;
    vec3 hdrColor = texture(material.sourceTexture, texCoords0).rgb;

    // Exposure tone mapping
    vec3 mapped = vec3(1.0) - exp(-hdrColor * exposure);
    // gamma correction
    mapped = pow(mapped, vec3(1.0 / gamma));

    gl_FragColor = vec4(mapped, 1.0);

}
