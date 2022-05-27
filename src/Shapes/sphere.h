#pragma once

#include "../maze.h"
#include "renderable_shape.h"

namespace Shapes
{
    class Sphere : public RendShape
    {
    public:
        Sphere(glm::vec3 pos, float radius, uint32_t sectors, uint32_t stacks);
        virtual ~Sphere() {};
        inline virtual glm::vec3 getCenterPos() const { return _position; };
        inline virtual float getRadius() const { return _radius; };

    protected:
        glm::vec3 _position;
        float _radius;
        void setIndices(std::vector<uint32_t>&, uint32_t,uint32_t,uint32_t,uint32_t);
        void setLastStackIndices(std::vector<uint32_t>&, uint32_t,uint32_t,uint32_t);
    };

} // namespace Shapes
