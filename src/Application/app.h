#pragma once

#include "../maze.h"
#include "window.h"

namespace Application
{
    class App
    {
        using TimeStamp = std::chrono::steady_clock::time_point;
    public:
        App(const App&) = delete;
        App(App&) = delete;
        App(App&&) = delete;

        static App* CreateInstance();
        ~App();
        void run();
        inline void setUpdateFunc(std::function<void()> func){ _update = func; }
        inline Window& getWindow(){ return _window; }
        float getElapsedTime();
    private:
        TimeStamp  _start_point;
        TimeStamp  _last_tick;
        Window _window;
        static App* s_instance;
        std::function<void()> _update;

        App();
    };
    
} // namespace Application
