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
        GLCHECK(glBindVertexArray(_id));
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }

    void VertexArray::addBuffer(const VertBuffer& vb, const BufferLayout& bl){
        bind();
        vb.bind();

        const auto& elems = bl.getElements();
        uint32_t offset = 0;
        for(uint32_t i = 0; i < elems.size(); ++i){
            const auto& elem = elems[i];
            uint32_t stride = bl.getStride();
            GLCHECK(glEnableVertexAttribArray(i));
            GLCHECK(glVertexAttribPointer(i, elem.count, elem.type, elem.normolized, stride, reinterpret_cast<void*>(offset)));
            offset += elem.count * LayouteElement::GetTypeSize(elem.type);
        }
    }

} // namespace Rendering
