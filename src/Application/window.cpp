#include "window.h"

namespace Application
{
    Window::Window() : _name("aMAZEing") 
    {

        if (!glfwInit())
        {
            _isValid = false;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        _window = glfwCreateWindow(_width, _heigth, _name.c_str(), nullptr, nullptr);
        if (_isValid = _window != nullptr)
        {
            glfwMakeContextCurrent(_window);
            if (_isValid = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                GLCHECK(glViewport(0, 0, _width, _heigth));
                GLCHECK(glfwSwapInterval(1));
                GLCHECK(glEnable(GL_BLEND));
                GLCHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
                GLCHECK(glEnable(GL_DEPTH_TEST));
                GLCHECK(glEnable(GL_CULL_FACE));
                GLCHECK(glFrontFace(GL_CW));
            }
            else
                _window = nullptr;
        }
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::setMousePosCallback(GLFWcursorposfun func)
    {
        glfwSetCursorPosCallback(_window,  func);
    }

    void Window::setMouseKeyCallback(GLFWmousebuttonfun func)
    {
        glfwSetMouseButtonCallback(_window, func);
    }

    void Window::setKeyCallback(GLFWkeyfun func)
    {
        glfwSetKeyCallback(_window, func);
    }

    void Window::setCursorLock(bool isLock){
        _cursorLocked = isLock;
        if(isLock)
            glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        else
            glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

} // namespace Application
