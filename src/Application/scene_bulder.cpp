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

    void SceneBuilder:: AddStaticRenderable(const Shapes::RendShape& obj,
    glm::vec3 scale, glm::vec3 pos, glm::vec3 rot, std::shared_ptr<Rendering::Texture> tex){
        _p_instance->_scene.emplace_back(Rendering::StaticRenderable::Create(obj,scale, pos, rot, tex));
    }

    SceneManager* SceneBuilder::Build(){
        return _p_instance;
    }

    SceneManager* SceneBuilder::Create(Window* window){
        StartCreation();
        SetWindow(window);
        SetCamera(new Rendering::Camera3d());
        auto box_tex = std::make_shared<Rendering::Texture>(  Helpers::image_location("/box.jpg"));
        auto earth_tex = std::make_shared<Rendering::Texture>(Helpers::image_location("/earth.jpg"));
        auto grass_tex = std::make_shared<Rendering::Texture>( Helpers::image_location("/grass.jpg"));
        auto sun_tex = std::make_shared<Rendering::Texture>( Helpers::image_location("/sun.jpg"));

        AddStaticRenderable(Shapes::Sphere(64, 32), glm::vec3(2.2f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.1f, 0.4f), sun_tex);
        AddStaticRenderable(Shapes::Sphere(54, 24), glm::vec3(0.5f), glm::vec3(2.5f, 0.0f, 0.0f), glm::vec3(1.0f, 3.1f, 0.4f), earth_tex);
        AddStaticRenderable(Shapes::Sphere(10, 10), glm::vec3(1.1f), glm::vec3(4.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.1f, -.4f), grass_tex);
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(1.0f), glm::vec3(5.0f, 0.0f, 3.0f), glm::vec3(1.0f, 5.1f, 5.4f), earth_tex);
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(1.0f), glm::vec3(4.0f, 3.0f, -.5f), glm::vec3(1.0f, 0.1f, 0.4f));
        AddStaticRenderable(Shapes::Sphere(16, 16), glm::vec3(1.2f), glm::vec3(6.0f, 0.0f, 5.0f), glm::vec3(1.0f, 6.1f, 2.4f));
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(1.0f), glm::vec3(7.0f, 5.0f, 1.0f), glm::vec3(1.0f, 3.1f, 2.4f), grass_tex);
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(1.0f), glm::vec3(3.0f, 0.0f,11.0f), glm::vec3(1.0f, 2.1f, 6.2f), box_tex);
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(3.0f), glm::vec3(6.0f, 2.0f,10.0f), glm::vec3(1.0f, 0.1f, 2.4f), box_tex);
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(1.0f), glm::vec3(5.0f, 0.0f,-8.0f), glm::vec3(2.0f, 2.1f, 4.4f));
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(0.1f), glm::vec3(0.2f, 0.8f, 8.0f), glm::vec3(0.0f            ), grass_tex);
        AddStaticRenderable(Shapes::Cube(),         glm::vec3(1.0f), glm::vec3(15.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.1f, 1.4f));
        AddStaticRenderable(Shapes::Cube(),glm::vec3(100.f, 0.3f, 150.f), glm::vec3(-5.0f, -7.0f, -5.0f), glm::vec3(0.0f, 6.1f, 0.0f), grass_tex);
        return Build();
    }
} // namespace Application
