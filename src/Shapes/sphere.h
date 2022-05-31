#pragma once

#include "../maze.h"
#include "renderable_shape.h"

namespace Shapes
{
    class Sphere : public RendShape
    {
    public:
        Sphere(uint32_t sectors, uint32_t stacks);
        virtual ~Sphere() {};

    protected:
        void setIndices(std::vector<uint32_t>&, uint32_t,uint32_t,uint32_t,uint32_t);
        void setLastStackIndices(std::vector<uint32_t>&, uint32_t,uint32_t,uint32_t);
    };

} // namespace Shapes
