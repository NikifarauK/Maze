#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;

//uniform
mat4 model{ 1.0, 0.0, 0.0 ,0.0,
            0.0, 1.0, 0.0, 0.0,
            0.0, 0.0, 1.0, 0.0,
            0.0, 0.0, 0.0, 1.0};
uniform mat4 trans;
uniform mat4 projection;

void main(){
    gl_Position = projection * trans * model * vec4(position, 1.0);
    v_texCoord = texCoord;
}