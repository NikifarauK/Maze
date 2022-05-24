#pragma once

#include "../maze.h"
#include "window.h"
#include "../Rendering/camera3d.h"

namespace Application
{
    class SceneManager
    {
    public:
        SceneManager(/* args */);
        ~SceneManager();

        onKey(GLFWwindow*, int, int, int, int);
        onMouseMove(GLFWwindow*, double, double);
        
    private:
        Window& _window;
        Rendering::Camera3d& _camera;
    };
    
} // namespace Application
