#pragma once

#include "../maze.h"

namespace Application
{
    class Window
    {
    public:
        Window();
        ~Window();

        inline bool isValid(){return _isValid;}
        void setKeyCallback(GLFWkeyfun);
        void setMousePosCallback(GLFWcursorposfun);
        void setMouseKeyCallback(GLFWmousebuttonfun);
        void setCursorLock(bool isLock);

        inline bool shouldClose(){ return glfwWindowShouldClose(_window); };
        inline void pollEvents(){ glfwPollEvents(); }
        inline void swapBuffers() { glfwSwapBuffers(_window); }
        inline int32_t getWidth() { return _width; }
        inline int32_t getHeigth() { return _heigth; }
        inline float getAspRatio() { return static_cast<float>(_width) / _heigth; }
        inline void setTitle(const std::string& title) { glfwSetWindowTitle(_window, title.c_str()); };
        inline bool isCursorLocked() {return _cursorLocked; };

    private:
        bool _isValid = false;
        bool _cursorLocked = false;
        int32_t _width = 960;
        int32_t _heigth = 540;
        GLFWwindow* _window = nullptr;
        std::string _name;

        Window(const Window&) = delete;
        Window(Window&) = delete;
        Window(Window&&) = delete;
    };
    
} // namespace Application
