#pragma once

#include "../maze.h"
#include "renderable_shape.h"

namespace Shapes
{
    class Cube : public RendShape
    {
    public:
        Cube(glm::vec3, float);
        virtual ~Cube() {};
        inline virtual glm::vec3 getCenterPos(){ return _position + _side / 2; };

    protected:
        glm::vec3 _position;
        float _side;
    };

} // namespace Shapes
