#pragma once

#include "../maze.h"
#include "vertex_buffer.h"
#include "buffer_layout.h"

namespace Rendering
{
    class VertexArray
    {
    public:
        VertexArray(/* args */);
        ~VertexArray();
        void bind() const;
        void unbind() const;
        void addBuffer(const VertBuffer&, const BufferLayout&);
    private:
        uint32_t _id;
    };
    
} // namespace Rendering
