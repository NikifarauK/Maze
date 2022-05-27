#pragma once

#include "../maze.h"
#include "vertex_array.h"
#include "vertex_buffer_static.h"
#include "index_buffer_static.h"
#include "shader.h"
#include "texture.h"
#include "../Shapes/renderable_shape.h"

namespace Rendering
{
    class StaticRenderable
    {
    public:
        ~StaticRenderable();
        static StaticRenderable* Create(const Shapes::RendShape&, std::shared_ptr<Texture>tex=nullptr);

        inline void setMatrix4f(const std::string& name, glm::mat4 val){ _shader->setUniform_m4f(name, val); };
        inline void setVector3f(const std::string& name, glm::vec3 val){ _shader->setUniform_v3f(name, val); };
        inline void setFloat   (const std::string& name, float val)    { _shader->setUniform_f  (name, val); };
        inline void setInt     (const std::string& name, int val)      { _shader->setUniform_i  (name, val); };
        void Render() const;
    private:
        VertexArray *_vArray;
        VertBuffer  *_vBuff;
        IndexBuffer *_iBuff;
        Shader      *_shader;

        std::shared_ptr<Texture> _texture;

        StaticRenderable();
    };

} // namespace Rendering
