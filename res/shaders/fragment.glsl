#version 330 core

in vec2 v_texCoord;
in vec3 v_norm;
in vec3 v_fragPos;

out vec4 color;

uniform float green;
uniform vec3 ligth_direction;
uniform vec3 view_pos;

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

//    vec3 rgb = vec3(0.7, 0.3, 0.4);
    vec3 ligth_color = vec3(1.0);

    //ambient + diffuse
    float ligth_mod = max(0.08, (dot(v_norm, ligth_direction)));
    vec3 amb_dif_col = ligth_color * ligth_mod;

    //specular
    float strength = 0.5;
    vec3 view_dir = normalize(view_pos - v_fragPos);
    vec3 reflect_dir = reflect(-ligth_direction, v_norm);
    strength *= pow(max(dot(view_dir, reflect_dir), 0.0), 64);
    vec3 spec_col = ligth_color * strength;

    color = vec4((amb_dif_col + spec_col) * rgb, 1.0);


}