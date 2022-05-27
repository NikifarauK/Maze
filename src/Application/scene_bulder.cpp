#include "scene_bulder.h"
#include "../Shapes/cube.h"
#include "../Shapes/sphere.h"
#include "../helpers.h"

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

    void SceneBuilder:: AddStaticRenderable(const Shapes::RendShape& obj, std::shared_ptr<Rendering::Texture> tex){
        _p_instance->_scene.emplace_back(Rendering::StaticRenderable::Create(obj, tex));
    }

    SceneManager* SceneBuilder::Build(){
        return _p_instance;
    }

    SceneManager* SceneBuilder::Create(Window* window){
        StartCreation();
        SetWindow(window);
        SetCamera(new Rendering::Camera3d());
        auto str = Helpers::parent_path();
        auto box_tex = std::make_shared<Rendering::Texture>(str+"/../res/img/box.jpg");
        auto earth_tex = std::make_shared<Rendering::Texture>(str+"/../res/img/earth.jpg");
        auto scrn_tex = std::make_shared<Rendering::Texture>(str+"/../res/img/scrn.png");

        AddStaticRenderable(Shapes::Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, 64, 64), earth_tex);
        AddStaticRenderable(Shapes::Sphere(glm::vec3(0.0f, 5.0f, 0.0f), 0.8f, 5, 5));
        AddStaticRenderable(Shapes::Cube(glm::vec3(5.0f, 0.0f, 0.0f),   2), box_tex);
        AddStaticRenderable(Shapes::Cube(glm::vec3(5.0f, 5.0f, 0.0f),   2));
        AddStaticRenderable(Shapes::Cube(glm::vec3(0.0f, 5.0f, 5.0f),   2));
        AddStaticRenderable(Shapes::Cube(glm::vec3(5.0f, 0.0f, 5.0f),   2), scrn_tex);
        AddStaticRenderable(Shapes::Cube(glm::vec3(-5.0f, 0.0f, 0.0f),  2), box_tex);
        AddStaticRenderable(Shapes::Cube(glm::vec3(-5.0f, -5.0f, 0.0f), 2), box_tex);
        AddStaticRenderable(Shapes::Cube(glm::vec3(-5.0f, 0.0f, -5.0f), 2));
        AddStaticRenderable(Shapes::Cube(glm::vec3(0.0f, -5.0f, 0.0f),  2), scrn_tex);
        AddStaticRenderable(Shapes::Cube(glm::vec3(5.0f, -5.0f, 5.0f),  2));
        AddStaticRenderable(Shapes::Cube(glm::vec3(-5.0f, 0.0f, 5.0f),  2));
        return Build();
    }
} // namespace Application
