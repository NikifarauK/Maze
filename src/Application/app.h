#pragma once

#include "../maze.h"
#include "window.h"
#include "scene_manager.h"

namespace Application
{
    class App
    {
    public:
        App(const App&) = delete;
        App(App&) = delete;
        App(App&&) = delete;

        static App* CreateInstance();
        ~App();
        void run(SceneManager&);
        inline void setUpdateFunc(std::function<void()> func){ _update = func; }
        inline Window& getWindow(){ return _window; }
        inline Window* getWindowPointer(){ return &_window; }
        
        float getElapsedTime();
    private:
        float _start_point;
        float _last_tick;
        Window _window;
        static App* s_instance;
        std::function<void()> _update;

        App();
    };
    
} // namespace Application
