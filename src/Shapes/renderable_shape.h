#pragma once

#include "../maze.h"
#include "vertex.h"

namespace Shapes
{
    class RendShape
    {
    public:
        virtual ~RendShape(){};

        inline virtual uint32_t getVertCount() const { return static_cast<uint32_t>(_vertices.size() * sizeof(Vertex) / sizeof(float)); }
        inline virtual uint32_t getVertSize() const { return static_cast<uint32_t>(_vertices.size() * sizeof(Vertex)); }
        inline virtual const void *getVertData() const { return _vertices.data(); }

        inline virtual uint32_t getIndicesCount() const { return static_cast<uint32_t>(_indices.size()); }
        inline virtual uint32_t getIndicesSize() const { return static_cast<uint32_t>( _indices.size() * sizeof(uint)); }
        inline virtual const uint32_t* getIndicesData() const { return _indices.data(); }
        
        inline const std::string& getName() const { return _name; };
        inline void setName(std::string name) { _name = name; };
    protected:
        inline RendShape(std::string name) : _name{name} {};
        std::string _name;
        std::vector<Vertex> _vertices;
        std::vector<uint32_t> _indices;
    };

} // namespace Shape
