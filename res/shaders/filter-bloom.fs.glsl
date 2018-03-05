#version 330 core

in vec2 texCoords0;



struct Material{
    sampler2D sourceTexture;
};

uniform vec3 blurScale;
uniform Material material;
uniform float exposure;

void main() {
    vec3 hdrColor = texture(material.sourceTexture, texCoords0).rgb;

    // Exposure tone mapping
    vec3 mapped = vec3(1.0) - exp(-hdrColor * exposure);

    float brightness = dot(hdrColor.rgb, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        gl_FragColor = vec4(hdrColor.rgb, 1.0);
    else
        gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);

}
