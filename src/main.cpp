#include "maze.h"
#include "Shapes/line.h"
#include "Shapes/cube.h"
#include "Application/app.h"
#include "Rendering/static_renderable.h"
#include "Application/scene_bulder.h"


int main(int argc, char**argv)
{
    using namespace Shapes;
    using namespace Application;

    App* app = App::CreateInstance();
    app->setUpdateFunc([](){});
    auto scene_manager = SceneBuilder().Create(app->getWindowPointer());
    app->run(*scene_manager);

    delete app;
    return 0;
}