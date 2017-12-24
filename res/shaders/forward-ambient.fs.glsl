#version 330 core

in vec2 texCoords0;

uniform sampler2D sampler;
uniform vec3 ambientIntensity;

void main(){

    gl_FragColor = texture2D(sampler, texCoords0) * vec4(ambientIntensity, 1.0);
}