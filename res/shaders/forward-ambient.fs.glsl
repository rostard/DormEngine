#version 330 core
in vec2 texCoords0;

uniform vec3 ambientLight;
uniform sampler2D diffuse;

void main(){
    gl_FragColor = texture2D(diffuse, texCoords0) * vec4(ambientLight, 1.0);
}