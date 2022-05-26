#include "scene_bulder.h"
#include "../Shapes/cube.h"

namespace Application
{
    SceneBuilder::SceneBuilder() : _p_instance{} {}

    SceneBuilder::~SceneBuilder() {}

    void SceneBuilder::StartCreation(){
        _p_instance = new SceneManager();
    }

    void SceneBuilder::SetWindow(Window* window){
        ASSERT(window);
        _p_instance->_p_window = window;
        window->setKeyCallback(SceneManager::onKey);
        window->setMousePosCallback(SceneManager::onMouseMove);
    }

    void SceneBuilder::SetCamera(Rendering::Camera3d* camera){
        ASSERT(camera);
        _p_instance->_p_camera = camera;
        camera->setDirection(glm::vec3(1,0,0));
    }

    void SceneBuilder:: AddStaticRenderable(Shapes::RendShape* obj){
        _p_instance->_scene.emplace_back(Rendering::StaticRenderable::Create(obj));
    }

    SceneManager* SceneBuilder::Build(){
        return _p_instance;
    }

    SceneManager* SceneBuilder::Create(Window* window){
        StartCreation();
        SetWindow(window);
        SetCamera(new Rendering::Camera3d());
        AddStaticRenderable(new Shapes::Cube(glm::vec3(0.0f, 0.0f, 5.0f),   4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(0.0f, 5.0f, 0.0f),   4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(5.0f, 0.0f, 0.0f),   4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(5.0f, 5.0f, 0.0f),   4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(0.0f, 5.0f, 5.0f),   4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(5.0f, 0.0f, 5.0f),   4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(-5.0f, 0.0f, 0.0f),  4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(-5.0f, -5.0f, 0.0f), 4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(-5.0f, 0.0f, -5.0f), 4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(0.0f, -5.0f, 0.0f),  4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(5.0f, -5.0f, 5.0f),  4));
        AddStaticRenderable(new Shapes::Cube(glm::vec3(-5.0f, 0.0f, 5.0f),  4));
        return Build();
    }
} // namespace Application
