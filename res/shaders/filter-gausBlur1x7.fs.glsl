#version 330 core

in vec2 texCoords0;



struct Material{
    sampler2D sourceTexture;
};

uniform vec3 blurScale;
uniform Material material;

void main() {
    vec4 color = vec4(0.0);

    color += texture2D(material.sourceTexture, texCoords0 + (vec2(-3.0) * blurScale.xy)) * (1.0/64.0);
    color += texture2D(material.sourceTexture, texCoords0 + (vec2(-2.0) * blurScale.xy)) * (6.0/64.0);
    color += texture2D(material.sourceTexture, texCoords0 + (vec2(-1.0) * blurScale.xy)) * (15.0/64.0);
    color += texture2D(material.sourceTexture, texCoords0 + (vec2(0.0) * blurScale.xy))  * (20.0/64.0);
    color += texture2D(material.sourceTexture, texCoords0 + (vec2(1.0) * blurScale.xy))  * (15.0/64.0);
    color += texture2D(material.sourceTexture, texCoords0 + (vec2(2.0) * blurScale.xy))  * (6.0/64.0);
    color += texture2D(material.sourceTexture, texCoords0 + (vec2(3.0) * blurScale.xy))  * (1.0/64.0);

    gl_FragColor = color;

}
