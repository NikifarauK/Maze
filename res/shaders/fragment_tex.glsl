#version 330 core

in vec2 v_texCoord;
in vec3 v_norm;

out vec4 color;

uniform float green;
uniform vec3 ligth_direction;
uniform sampler2D u_Tex;

void main(){
    color = texture(u_Tex, v_texCoord);
    color[1] = green/5 > color[1] ? green/5 : color[1];
    float ligth_mod = max(0.05, dot(v_norm, ligth_direction));
    color = color * ligth_mod;
    color[3] = 1.0;
}
