#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;

out vec2 v_texCoord;
out vec3 v_norm;
out vec3 v_fragPos;

uniform mat4 model;
uniform mat4 trans;
uniform mat4 projection;
uniform mat3 norm_matrix;

void main(){
    gl_Position = projection * trans * model * vec4(position, 1.0);
    v_texCoord = texCoord;
    v_norm = normalize(norm_matrix * normal);
    v_fragPos = vec3(model * vec4(position, 1.0));
}