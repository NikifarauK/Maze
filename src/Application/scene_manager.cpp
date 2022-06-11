#include "scene_manager.h"
#include <sstream>
#include <iomanip>

namespace Application
{
    float SceneManager::s_x_mouse = 0.0f;
    float SceneManager::s_y_mouse = 0.0f;
    std::vector<bool> SceneManager::s_keys(512, false);

    SceneManager::SceneManager()
    : _mouse_sens{0.035f}, _speed{6.5f}, 
      _yaw{}, _pitch{}, _last_mouse_x{}, _last_mouse_y{},
      _pos(1,0,0),
      _p_window{}, _p_camera{}, _scene{}  
    {}

    SceneManager::~SceneManager(){
        // delete _p_window;
        delete _p_camera;
        for(auto p : _scene)
            delete p;
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
        if(!_p_window->isCursorLocked())
            return;
        float x_offset = _mouse_sens * (s_x_mouse - _last_mouse_x);
        float y_offset = _mouse_sens * (_last_mouse_y - s_y_mouse);
        _last_mouse_x = s_x_mouse;
        _last_mouse_y = s_y_mouse;
        _yaw += x_offset;
        _pitch -= y_offset;
        if(_pitch > 89.5f) _pitch = 89.5f;
        if(_pitch < -89.5f) _pitch = -89.5f;
        glm::vec3 f{
            cos(glm::radians(_pitch)) * cos (glm::radians(_yaw)),
            sin(glm::radians(_pitch)),
            cos(glm::radians(_pitch)) * sin(glm::radians(_yaw))
        };

        _p_camera->setDirection(glm::normalize(f));
    }

    void SceneManager::keyHandler(float elapsed_time){
        if(s_keys[GLFW_KEY_W] || s_keys[GLFW_KEY_UP])
            _pos -= _p_camera->getDirection() * _speed * elapsed_time;
        if(s_keys[GLFW_KEY_S] || s_keys[GLFW_KEY_DOWN])
            _pos += _p_camera->getDirection() * _speed * elapsed_time;

        if(s_keys[GLFW_KEY_A] || s_keys[GLFW_KEY_LEFT])
            _pos += glm::normalize(glm::cross(_p_camera->getDirection(), glm::vec3{0.0f, 1.0f, 0.0f}))* _speed * elapsed_time;
        if(s_keys[GLFW_KEY_D] || s_keys[GLFW_KEY_RIGHT])
            _pos -= glm::normalize(glm::cross(_p_camera->getDirection(), glm::vec3{0.0f, 1.0f, 0.0f}))* _speed * elapsed_time;

        if(s_keys[GLFW_KEY_Q] || s_keys[GLFW_KEY_E])
            _pos += _p_camera->getUp() * _speed * elapsed_time;
        if(s_keys[GLFW_KEY_X] || s_keys[GLFW_KEY_Z])
            _pos -= _p_camera->getUp() * _speed * elapsed_time;
            
        if(s_keys[GLFW_KEY_1]) {
            _p_window->setCursorLock(true);
            _last_mouse_x = s_x_mouse;
            _last_mouse_y = s_y_mouse;
        }
        if(s_keys[GLFW_KEY_2]) _p_window->setCursorLock(false);
        _p_camera->setPos(_pos);
    }

    void SceneManager::UpdateAndRender(float elapsed_time){
        static float green = 0.0f;
        static std::vector<float> modifiers =
          [&](){static std::vector<float> x; auto size = _scene.size();float m = 13.f; 
                    while(size--)x.emplace_back(m -= 1.f); return x;}();
        static float rotation = 0.0f;
        static float m = 0.35f;
        mouseHandler();
        keyHandler(elapsed_time);
        auto m4View = _p_camera->GetViewMatrix();
        auto m4Persp = _p_camera->GetPerspectiveMatrix(_p_window->getAspRatio());
        glClearColor(0.1f, 0.23f, 0.45f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        float circle = glm::pi<float>() * 2;
        int i = 0;
        glm::vec3 ligth_dir = glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f));
        for (auto obj : _scene){
            obj->setMatrix4f("projection", m4Persp);
            obj->setMatrix4f("trans", m4View);
            obj->setFloat("green", green);
            obj->setVector3f("ligth_direction", ligth_dir);
            obj->addToRot(glm::vec3(0, rotation * modifiers[i++], 0));
            obj->UpdateAndRender();
        }
        // rotation += rotation < circle ? 0.00003f * elapsed_time : -circle;
        m = green <= 1.0f && green >= 0.0f ? m : (m * -1);
        green +=  m * elapsed_time;
        std::stringstream title;
        auto dir = _p_camera->getDirection();
        title << std::fixed << std::setprecision(3)
              << "pos: " << _pos.x << "," << _pos.y << "," << _pos.z
              << " dir: " << dir.x << "," << dir.y << "," << dir.z
              << " fps: " << std::setw(7) << 1.0f / elapsed_time;
        _p_window->setTitle(title.str());
    }
} // namespace Application
