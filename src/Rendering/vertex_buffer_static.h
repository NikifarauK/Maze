#pragma once

#include "../maze.h"
#include "vertex_buffer.h"
#include "../Shapes/vertex.h"

namespace Rendering
{
    class VertBufferStatic : public VertBuffer
    {
    public:
        VertBufferStatic(const void*, uint32_t);
        ~VertBufferStatic() override;

        void bind() const override;
        void unbind() const override;
    };
    
} // namespace Rendering
