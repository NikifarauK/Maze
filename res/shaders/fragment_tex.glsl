#version 330 core

in vec2 v_texCoord;
in vec3 v_norm;
in vec3 v_fragPos;

out vec4 color;

uniform float green;
uniform vec3 ligth_direction;
uniform sampler2D u_Tex;
uniform vec3 view_pos;

void main(){
    color = texture(u_Tex, v_texCoord);
    color[1] = green/8 > color[1] ? green/5 : color[1];

    vec3 obj_color = vec3(color);

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

    color = vec4((amb_dif_col + spec_col) * obj_color, color[3]);
}
