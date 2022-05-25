#include "scene_manager.h"

namespace Application
{
    bool s_cursor_lock = false;
    float SceneManager::s_x_mouse = 0.0f;
    float SceneManager::s_y_mouse = 0.0f;
    std::vector<bool> SceneManager::s_keys(512, false);

    SceneManager::SceneManager()
    : _mouse_sens{0.075f}, _speed{5.5f}, 
      _yaw{}, _pitch{}, _last_mouse_x{}, _last_mouse_y{},
      _pos{},
      _p_window{}, _p_camera{}, _scene{}  
    {}

    SceneManager::~SceneManager(){
        // delete _p_window;
        delete _p_camera;
    }

    void SceneManager::onKey(GLFWwindow*, int key, int scancode, int action, int mode){
        if(key == -1 || key >= s_keys.size()) return;

        if(action == GLFW_PRESS) s_keys[key] = true;
        if(action == GLFW_RELEASE) s_keys[key] = false;
    }

    void SceneManager::onMouseMove(GLFWwindow*, double x, double y){
        s_x_mouse = static_cast<float>(x);
        s_y_mouse = static_cast<float>(y);
    }

    void SceneManager::mouseHandler(){
        float x_offset = _mouse_sens * (s_x_mouse - _last_mouse_x);
        float y_offset = _mouse_sens * (_last_mouse_y - s_y_mouse);
        _last_mouse_x = s_x_mouse;
        _last_mouse_y = s_y_mouse;
        _yaw += x_offset;
        _pitch += y_offset;
        if(_pitch > 89.5f) _pitch = 89.5f;
        if(_pitch < -89.5f) _pitch = -89.5f;
        glm::vec3 f{
            cos(glm::radians(_pitch)) * cos (glm::radians(_yaw)),
            sin(glm::radians(_pitch)),
            cos(glm::radians(_pitch)) * sin(glm::radians(_yaw))
        };

        _p_camera->setDirection(f);
    }

    void SceneManager::keyHandler(float elapsed_time){
        if(s_keys[GLFW_KEY_W] || s_keys[GLFW_KEY_UP])
            _pos += _p_camera->getDirection() * _speed * elapsed_time;
        if(s_keys[GLFW_KEY_S] || s_keys[GLFW_KEY_DOWN])
            _pos -= _p_camera->getDirection() * _speed * elapsed_time;

        if(s_keys[GLFW_KEY_A] || s_keys[GLFW_KEY_LEFT])
            _pos -= glm::normalize(glm::cross(_p_camera->getDirection(), glm::vec3{0.0f, 1.0f, 0.0f}))* _speed * elapsed_time;
        if(s_keys[GLFW_KEY_ESCAPE]) _p_window->setCursorLock(s_cursor_lock = ! s_cursor_lock);
    }
} // namespace Application
