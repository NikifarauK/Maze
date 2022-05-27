#pragma once

#include "../maze.h"

namespace Shapes
{
    // on change also change buffer_layout.h Push<Vertex>
    struct Vertex
    {
        Vertex(){};
        Vertex(glm::vec3 pos, glm::vec2 tex);
        Vertex(glm::vec3, float, float);
        Vertex(float, float, float, float, float);
        float x, y, z;
        float tx, ty;
    };

    inline Vertex::Vertex(glm::vec3 pos, glm::vec2 tex) 
        : x{pos.x}, y{pos.y}, z{pos.z}, tx{tex.x}, ty{tex.y} {}
    inline Vertex::Vertex(float nx, float ny, float nz, float ntx, float nty)
        : x{nx}, y{ny}, z{nz}, tx{ntx}, ty{nty} {}
    inline Vertex::Vertex(glm::vec3 pos, float nx, float ny) 
        : x{pos.x}, y{pos.y}, z{pos.z}, tx{nx}, ty{ny} {}
     
} // namespace Shapes