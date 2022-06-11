#version 330 core

in vec2 v_texCoord;
in vec3 v_norm;

out vec4 color;

uniform float green;
uniform vec3 ligth_direction;

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
    
    float ligth_mod = max(0.05, (dot(v_norm, ligth_direction)));
    color = vec4(rgb * ligth_mod, 1.0);
}