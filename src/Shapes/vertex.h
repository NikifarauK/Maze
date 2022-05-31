#pragma once

#include "../maze.h"

namespace Shapes
{
    // on change also change buffer_layout.h Push<Vertex> and RendShape
    struct Vertex
    {
        Vertex(){};
        Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 tex);
        Vertex(glm::vec3, glm::vec3, float, float);
        Vertex(float, float, float, float, float, float, float, float);
        float x,  y,  z;
        float nx, ny, nz;
        float tx, ty;
    };

    inline Vertex::Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 tex) 
        : x{pos.x}, y{pos.y}, z{pos.z}, nx{norm.x}, ny{norm.y}, nz{norm.z}, tx{tex.x}, ty{tex.y} {}

    inline Vertex::Vertex(float px, float py, float pz,float nnx, float nny, float nnz,  float ntx, float nty)
        : x{px}, y{py}, z{pz}, nx{nnx}, ny{nny}, nz{nnz}, tx{ntx}, ty{nty} {}

    inline Vertex::Vertex(glm::vec3 pos, glm::vec3 norm, float nx, float ny) 
        : x{pos.x}, y{pos.y}, z{pos.z}
        , nx{norm.x}, ny{norm.y}, nz{norm.z}
        , tx{nx}, ty{ny} {}
     
} // namespace Shapes