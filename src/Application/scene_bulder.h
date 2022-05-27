#pragma once

#include "../maze.h"
#include "scene_manager.h"
#include "../Shapes/renderable_shape.h"


namespace Application
{
    class SceneBuilder
    {
    public:
        SceneBuilder();
        ~SceneBuilder();    
        void StartCreation();
        void SetWindow(Window*);
        void SetCamera(Rendering::Camera3d*);
        void AddStaticRenderable(const Shapes::RendShape&);
        SceneManager* Build();
        virtual SceneManager* Create(Window*);
    protected:
        SceneManager * _p_instance;
    };

} // namespace Application
