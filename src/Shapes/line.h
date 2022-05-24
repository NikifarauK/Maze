#pragma once
#include "../maze.h"

namespace Shapes
{
    class Line
    {
    private:
        glm::vec3 _point;
        glm::vec3 _direction;
    public:
        Line(glm::vec3, glm::vec3) noexcept;
        ~Line();
        float getDistanceToPoint(glm::vec3);
    };  
} // namespace Graphics
