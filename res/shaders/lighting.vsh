layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texCoords;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec3 tangent;

out vec2 texCoords0;
out vec3 normal0;
out vec3 worldPos0;
out mat3 TBN;

uniform mat4 worldMatrix;
uniform mat4 MVP;

void main() {
    normal0 = normalize(mat3(transpose(inverse(worldMatrix))) * normal);
    texCoords0 = texCoords;
    worldPos0 = vec3(worldMatrix * vec4(pos, 1.0));

    vec3 T = normalize(vec3(worldMatrix * vec4(tangent, 0.0)));
    vec3 N = normalize(vec3(worldMatrix * vec4(normal, 0.0)));
    // re-orthogonalize T with respect to N
    T = normalize(T - dot(T, N) * N);
    // then retrieve perpendicular vector B with the cross product of T and N
    vec3 B = cross(T, N);

    TBN = mat3(T, B, N);

    gl_Position = MVP * vec4(pos, 1.0);
}
