#pragma once

#include "../maze.h"
#include "gl_buff_container.h"
#include "shader.h"
#include "texture.h"
#include "../Shapes/renderable_shape.h"

namespace Rendering
{
    class StaticRenderable
    {
    public:
        ~StaticRenderable();
        static StaticRenderable* Create
        (const Shapes::RendShape&, glm::vec3 scale,
         glm::vec3 pos, glm::vec3 rot,
         std::shared_ptr<Texture>tex=nullptr);

        void UpdateAndRender();
        inline void setPos(glm::vec3 p){ _pos = p; };
        inline void setScale(glm::vec3 s){ _scale = s; };
        inline void setRot(glm::vec3 r){ _rot = r; };
        inline glm::vec3 getPos(){ return _pos; };
        inline glm::vec3 getScale(){ return _scale; };
        inline glm::vec3 getRot(){ return _rot; };
        inline void addToPos(glm::vec3 p){ _pos += p; };
        inline void addToRot(glm::vec3 r){ _rot += r; };
        
        inline void setMatrix4f(const std::string& name, glm::mat4 val){ p_shader->setUniform_m4f(name, val); };
        inline void setMatrix3f(const std::string& name, glm::mat3 val){ p_shader->setUniform_m3f(name, val); };
        inline void setVector3f(const std::string& name, glm::vec3 val){ p_shader->setUniform_v3f(name, val); };
        inline void setFloat   (const std::string& name, float val)    { p_shader->setUniform_f  (name, val); };
        inline void setInt     (const std::string& name, int val)      { p_shader->setUniform_i  (name, val); };
    private:
        glm::vec3 _scale;
        glm::vec3 _pos;
        glm::vec3 _rot;
        
        std::shared_ptr<GLBuffConteiner>p_glBuffer;
        std::shared_ptr<Shader>  p_shader;

        std::shared_ptr<Texture> p_texture;

        StaticRenderable();
        void updateModelMatrix();
        glm::mat3 getNormalMatrix(const glm::mat4&) const;
        glm::mat4 StaticRenderable::getModelMatrix() const;
    };

} // namespace Rendering
