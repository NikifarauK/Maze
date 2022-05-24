#include "index_buffer_static.h"

namespace Rendering
{
    IndexBufferStatic::IndexBufferStatic(const uint32_t* data, uint32_t count)
    : IndexBuffer(count) {
        glGenBuffers(1, &_id);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW);
    }

    IndexBufferStatic::~IndexBufferStatic(){
        glDeleteBuffers(1, &_id);
    }

    void IndexBufferStatic::bind() const{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    }
    
    void IndexBufferStatic::unbind() const{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
} // namespace Rendering
