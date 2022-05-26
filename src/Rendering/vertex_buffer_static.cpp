#include "vertex_buffer_static.h"

namespace Rendering
{
    VertBufferStatic::VertBufferStatic(const void* data, uint32_t size)
    : VertBuffer() {
        GLCHECK(glGenBuffers(1, &_id));
        bind();
        GLCHECK(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    VertBufferStatic::~VertBufferStatic(){
        glDeleteBuffers(1, &_id);
    }

    void VertBufferStatic::bind() const{
        glBindBuffer(GL_ARRAY_BUFFER, _id);
    }

    
    void VertBufferStatic::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // namespace Rendering
