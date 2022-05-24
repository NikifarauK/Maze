#include "app.h"

Application::App::App(){
    _start_point = _last_tick = std::chrono::steady_clock::now();
}

Application::App* Application::App::s_instance = nullptr;

void Application::App::run( ){
    if(!_window.isValid())
        return;
    std::cout << "windows created\n"; 
    
    while(!_window.shouldClose()){
       _window.pollEvents();
       _update();
    //    rc.Render();
       _window.swapBuffers();
    }
}

Application::App::~App(){
    _window.~Window();
    s_instance = nullptr;
}

Application::App* Application::App::CreateInstance(){
    if(s_instance == nullptr){
        s_instance = new App();
    }
    return s_instance;
}

float Application::App::getElapsedTime(){
    TimeStamp now = std::chrono::steady_clock::now();
    auto res = now - _last_tick;
    _last_tick = now;
    return res.count();
}