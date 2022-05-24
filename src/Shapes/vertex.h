#pragma once

namespace Shapes
{
    //on change also change buffer_layout.h Push<Vertex>
    struct Vertex
    {
        float x, y, z;
        float tx, ty;
    };
} // namespace Shapes