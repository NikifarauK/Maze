#pragma once

#include "../maze.h"

namespace Rendering
{
    class Camera3d
    {
    public:
        Camera3d(/* args */);
        ~Camera3d();
        inline glm::vec3 getPos() { return _position; }
        inline void setPos(glm::vec3 pos) { _position = pos; }
        inline glm::vec3 getDirection() { return _direction; }
        inline void setDirection(glm::vec3 dir) { _direction = dir; }
        inline glm::vec3 getUp() { return _up; };
        inline void setUp(glm::vec3 up) { _up = up; };
        glm::mat4 GetViewMatrix();
        glm::mat4 GetPerspectiveMatrix(float asp_ratio);

    private:
        glm::vec3 _position;
        glm::vec3 _direction;
        glm::vec3 _up;

        float _observe_angle;
        float _near;
        float _far;
    };

} // namespace Rendering
