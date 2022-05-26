#pragma once

#include "../maze.h"
#include "window.h"
#include "../Rendering/camera3d.h"
#include "../Rendering/static_renderable.h"

namespace Application
{
    class SceneManager
    {
    public:
        ~SceneManager();

        static void onKey(GLFWwindow*, int, int, int, int);
        static void onMouseMove(GLFWwindow*, double, double);
        void UpdateAndRender(float);
        inline void setMouseSens(float sens) {_mouse_sens = sens; };
        
        friend class SceneBuilder;
    private:
        float _mouse_sens;
        float _speed;
        float _yaw, _pitch, _last_mouse_x, _last_mouse_y;
        glm::vec3 _pos;
        Window* _p_window;
        Rendering::Camera3d* _p_camera;
        std::vector<Rendering::StaticRenderable*> _scene;
        static float s_x_mouse; 
        static float s_y_mouse; 
        static std::vector<bool> s_keys;

        inline float getAspRatio() { return _p_window->getAspRatio(); }; 
        SceneManager();
        void mouseHandler();
        void keyHandler(float);
    };
    
} // namespace Application
