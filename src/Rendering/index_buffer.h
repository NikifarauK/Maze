#pragma once

#include "../maze.h"

namespace Rendering
{
    class IndexBuffer
    {
    public:
        IndexBuffer(uint32_t count) : _count(count) {};
        virtual ~IndexBuffer() {};
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        virtual inline uint32_t getCount() { return _count; }
    protected:
        uint32_t _count;
    };
    
} // namespace Rendering
