#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;

out vec2 v_texCoord;
out vec3 v_norm;

uniform mat4 model;
uniform mat4 trans;
uniform mat4 projection;

void main(){
    gl_Position = projection * trans * model * vec4(position, 1.0);
    v_texCoord = texCoord;
    v_norm = vec3(normalize(mat3(model) * normal));
}