#version 330 core

struct BaseLight{
    vec3 color;
    float intensity;
};

struct Attenuation{
    float constant;
    float linear;
    float quadratic;
};

struct PointLight{
    BaseLight base;
    Attenuation attenuation;
    vec3 position;
    float range;
};


uniform vec3 viewPos;
uniform sampler2D texture_diffuse;
uniform float shininess;
uniform float specularIntensity;

uniform PointLight pointLight;


in vec2 texCoords0;
in vec3 normal0;
in vec3 worldPos0;


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir){

    float distance    = length(light.position - worldPos0);
    if(distance > light.range) return vec3(0.0);

    vec3 lightDir = normalize(light.position - worldPos0);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), shininess);

    vec3 diffuse = light.base.color * diff * light.base.intensity;
    vec3 specular = light.base.color * spec * specularIntensity;

    float attenuation = 1.0 / (light.attenuation.constant + light.attenuation.linear * distance + light.attenuation.quadratic * (distance * distance));

    return attenuation * (diffuse + specular);
}


void main() {
    vec3 totalColor = vec3(0, 0, 0);
    vec4 color = texture(texture_diffuse, texCoords0);

    vec3 normal = normalize(normal0);
    vec3 viewDir = normalize(viewPos - worldPos0);
    totalColor += CalcPointLight(pointLight, normal, viewDir);

    gl_FragColor = vec4(totalColor, 1.0) * color;
}
