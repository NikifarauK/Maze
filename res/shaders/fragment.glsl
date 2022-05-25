#version 330 core

in vec2 v_texCoord;

out vec4 color;

uniform float green;

void main(){
    color = vec4(v_texCoord.x, green, v_texCoord.y, 1.0);
}