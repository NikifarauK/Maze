#include "static_renderable.h"
#include "../helpers.h"

namespace Rendering
{
    StaticRenderable::StaticRenderable()
        : _scale{1.0f}, _pos{0.0f}, _rot{0.0f}, p_shader{}, p_texture{} {}

    StaticRenderable::~StaticRenderable(){}

    StaticRenderable* StaticRenderable::Create
        (const Shapes::RendShape& mesh, glm::vec3 scale,
        glm::vec3 pos, glm::vec3 rot, std::shared_ptr<Texture> tex){
        auto sr = new StaticRenderable;
        sr->p_glBuffer = GLBuffConteiner::Create(mesh);

        sr->_scale = scale;
        sr->_pos = pos;
        sr->_rot = rot;
        if(!tex){
            sr->p_shader = std::shared_ptr<Shader>(Shader::BuildShader(Helpers::shader_location("/vertex.glsl"),
             Helpers::shader_location("/fragment.glsl")));
        }
        else{
            sr->p_texture = tex; 
            sr->p_shader =std::shared_ptr<Shader>(Shader::BuildShader(Helpers::shader_location("/vertex.glsl"),
             Helpers::shader_location("/fragment_tex.glsl")));
            sr->p_texture->bind();
            sr->p_shader->setUniform_i("u_Tex", sr->p_texture->getSlot());
            sr->p_texture->unbind();
        }           

        return sr;
    }

    void StaticRenderable::UpdateAndRender(){
        p_shader->bind();
        updateModelMatrix();
        p_glBuffer->bind();
        if(p_texture)p_texture->bind();
        GLCHECK(glDrawElements(GL_TRIANGLES, p_glBuffer->getCount(), GL_UNSIGNED_INT, 0));
        if(p_texture)p_texture->unbind();
        p_glBuffer->unbind();
        p_shader->unbind();
    }

    void StaticRenderable::updateModelMatrix(){
        auto model = getModelMatrix();
        setMatrix4f("model", model);
        setMatrix3f("norm_matrix", getNormalMatrix(model));
    }
    glm::mat3 StaticRenderable::getNormalMatrix(const glm::mat4& model) const
    {
        auto normal = glm::mat3();
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                normal[j][i] = model[i][j];
        return glm::inverse(normal);
    }
    glm::mat4 StaticRenderable::getModelMatrix() const
    {
        auto model =glm::mat4(1.0f);
        model = glm::translate(model, _pos);
        model = glm::rotate(model, _rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, _rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, _rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, _scale);
        return model;
    }
} // namespace Rendering
