#version 330 core
#include "lighting.fsh"

uniform vec3 ambientLight;

#include "parallax.glh"

void main(){
    vec2 texCoords = GetParallaxCoords(material.dispMap, TBN, normalize(viewPos - worldPos0), texCoords0, material.dispMapScale, material.dispMapOffset);
    if(texCoords.x > 1.0 || texCoords.y > 1.0 || texCoords.x < 0.0 || texCoords.y < 0.0)
        discard;
    gl_FragColor = texture2D(material.diffuse, texCoords) * vec4(ambientLight, 1.0);
//    gl_FragColor = vec4(TBN * normalize(viewPos - worldPos0), 1.0);
//    gl_FragColor = vec4(texCoords0, 0.0, 1.0);
}
