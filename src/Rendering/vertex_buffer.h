#pragma once

#include "../maze.h"
#include "../Shapes/vertex.h"

namespace Rendering
{
    class VertBuffer
    {
    public:
        VertBuffer() : _id{} {};
        virtual ~VertBuffer() {};

        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    protected:
        uint32_t _id;
    };
    
} // namespace Rendering
