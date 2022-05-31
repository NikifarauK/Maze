#version 330 core

in vec2 v_texCoord;
in vec3 v_norm;

out vec4 color;

uniform float green;
uniform sampler2D u_Tex;

void main(){
    color = texture(u_Tex, v_texCoord);
    color[1] = green/5 > color[1] ? green/5 : color[1];
}
