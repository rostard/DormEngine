#version 330 core

struct BaseLight{
    vec3 color;
    float intensity;
};

struct DirectionalLight{
    BaseLight base;
    vec3 direction;
};


uniform vec3 viewPos;
uniform sampler2D texture_diffuse;
uniform float shininess;
uniform float specularIntensity;

uniform DirectionalLight dirLight;

vec3 CalcDirLight(DirectionalLight light, vec3 normal, vec3 viewDir){

    vec3 lightDir = normalize(-light.direction);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), shininess);

    vec3 diffuse = light.base.color * diff * light.base.intensity;
    vec3 specular = light.base.color * spec * specularIntensity;

    return diffuse + specular;
}


in vec2 texCoords0;
in vec3 normal0;
in vec3 worldPos0;

void main() {
    vec3 totalColor = vec3(0, 0, 0);
    vec4 color = texture(texture_diffuse, texCoords0);

    vec3 normal = normalize(normal0);
    vec3 viewDir = normalize(worldPos0 - viewPos);
    totalColor += CalcDirLight(dirLight, normal, viewDir);

//    gl_FragColor = vec4(totalColor, 1.0) * color;
    gl_FragColor = vec4(normal, 1.0);
}
