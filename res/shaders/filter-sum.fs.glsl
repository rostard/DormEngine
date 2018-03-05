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
    vec3 color1 = texture(material.sourceTexture1, texCoords0).rgb;
    vec3 color2 = texture(material.sourceTexture2, texCoords0).rgb;

    gl_FragColor = vec4(color1 + color2, 1.0);

}
