#pragma once

#include "../maze.h"
#include "index_buffer.h"

namespace Rendering
{
    class IndexBufferStatic : public IndexBuffer
    {
    public:
        IndexBufferStatic(const uint32_t* data, uint32_t count);
        ~IndexBufferStatic() override;

        void bind() const;
        void unbind() const;
    private:
        uint32_t _id;
    };
    
} // namespace Rendering
