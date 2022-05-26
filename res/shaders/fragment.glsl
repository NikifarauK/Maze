#version 330 core

in vec2 v_texCoord;

out vec4 color;

uniform float green;

void main(){
    vec3 rgb = vec3(v_texCoord.x, green, v_texCoord.y);
    float x = 1.0 - v_texCoord.x;
    float y = 1.0 - v_texCoord.y;
    if( x < 0.01 || y < 0.01 || v_texCoord.x < 0.01 || v_texCoord.y < 0.01){
        float a = x < y ? x : y;
        float b = v_texCoord.x < v_texCoord.y ? v_texCoord.x : v_texCoord.y;
        rgb *= a < b ? a : b;
        rgb *= 99.0;
    }
    
    color = vec4(rgb, 1.0);
}