#include "vertex_array.h"

namespace Rendering
{
    VertexArray::VertexArray() : _id{} {
        glGenVertexArrays(1, &_id);
        glBindVertexArray(_id);
    };

    VertexArray::~VertexArray(){
        glDeleteVertexArrays(1, &_id);
    }

    void VertexArray::bind() const {
        glBindVertexArray(_id);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }

} // namespace Rendering
