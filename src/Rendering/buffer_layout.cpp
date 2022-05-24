#include "buffer_layout.h"

namespace Rendering
{
    template <typename T>
    void BufferLayout::Push(uint32_t count)
    {
        ASSERT(false);
    }

    template <>
    void BufferLayout::Push<float>(uint32_t count)
    {
        ASSERT(sizeof(float) == sizeof(GLfloat));
        _layouts.push_back({GL_FALSE, count, GL_FLOAT});
        _stride += LayouteElement::GetTypeSize(GL_FLOAT) * count;
    }

    template <>
    void BufferLayout::Push<uint32_t>(uint32_t count)
    {
        ASSERT(sizeof(uint32_t) == sizeof(GLuint));
        _layouts.push_back({GL_FALSE, count, GL_UNSIGNED_INT});
        _stride += LayouteElement::GetTypeSize(GL_UNSIGNED_INT) * count;
    }

    template <>
    void BufferLayout::Push<uint8_t>(uint32_t count)
    {
        ASSERT(sizeof(uint8_t) == sizeof(GLubyte));
        _layouts.push_back({GL_TRUE, count, GL_UNSIGNED_BYTE});
        _stride += LayouteElement::GetTypeSize(GL_UNSIGNED_BYTE) * count;
    }

    template <>
    void BufferLayout::Push<Shapes::Vertex>(uint32_t count)
    {
        ASSERT(sizeof(Shapes::Vertex) == 5 * sizeof(float));
        Push<float>(3); // xyz to Layout[0]
        Push<float>(2); // text coords to Layout[1]
    }
} // namespace Rendering