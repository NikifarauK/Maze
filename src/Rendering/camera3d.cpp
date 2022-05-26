#include "camera3d.h"

namespace Rendering
{
    Camera3d::Camera3d() : _position{}, _direction{}, _up(0.0f, 1.0f, 0.0f), 
        _observe_angle{3.14159265f/4},
        _near{0.005f}, _far{50.f}
    {}

    glm::mat4 Camera3d::GetViewMatrix()
    {
        return glm::lookAt(_position, _position - _direction, _up);
    }

    glm::mat4 Camera3d::GetPerspectiveMatrix(float asp_ratio)
    {
        return glm::perspective(_observe_angle, asp_ratio, _near, _far);
    }

    Camera3d::~Camera3d()
    {
    }

} // namespace Rendering
