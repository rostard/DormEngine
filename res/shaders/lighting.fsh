
in vec2 texCoords0;
in vec3 normal0;
in vec3 worldPos0;
in mat3 TBN;
in vec4 lightPos0;

#include "lighting.glh"
#include "sampling.glh"

uniform vec3 shadowTexelSize;