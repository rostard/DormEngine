#version 330 core

uniform sampler2D tex;

in vec2 TexCoord;

void main(){

    vec3 texColor = texture(tex, TexCoord).rgb;
    gl_FragColor = vec4(texColor, 1.0);
}