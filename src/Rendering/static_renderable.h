#pragma once

#include "../maze.h"
#include "vertex_array.h"
#include "vertex_buffer_static.h"
#include "index_buffer_static.h"
#include "shader.h"
#include "../Shapes/renderable_shape.h"

namespace Rendering
{
    class StaticRenderable
    {
    public:
        ~StaticRenderable();
        static StaticRenderable Create(const Shapes::RendShape&);

        void Render() const;
    private:
        StaticRenderable(const Shapes::RendShape&);
        const Shapes::RendShape& _obj;
        VertexArray *_vArray;
        VertBuffer  *_vBuff;
        IndexBuffer *_iBuff;
        Shader      *_shader;
    };

} // namespace Rendering
