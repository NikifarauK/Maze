#include "maze.h"
#include "Shapes/line.h"
#include "Shapes/cube.h"
#include "Application/app.h"
#include "Rendering/shader.h"

int main()
{
    using namespace Shapes;
    using namespace Application;
    
    std::cout << sizeof(Rendering::Shader);

    Line line(glm::vec3{3.f, 1.f, -1.f}, glm::vec3{2.f, 1.f, 2.f});
    std::cout << line.getDistanceToPoint(glm::vec3{0.f, 2.f, 3.f}) << std::endl;
    auto cube = std::make_unique<Cube>(glm::vec3{1.0f,1.0f,1.0f}, 0.7f);

    App* app = App::CreateInstance();
    app->setUpdateFunc(
        [](){
            static float green = 0.f;
            glClearColor(1.0f, green, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            green +=0.005f;
            green = green > 1.0f ? 0.f : green;
        });
    app->run();

    delete app;
    return 0;
}