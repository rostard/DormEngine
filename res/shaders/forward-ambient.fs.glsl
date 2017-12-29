#version 330 core

in vec2 texCoords0;

uniform sampler2D sampler;
uniform vec3 ambientLight;

void main(){

    gl_FragColor = texture2D(sampler, texCoords0) * vec4(ambientLight, 1.0);
}