#pragma once

#include "../maze.h"
#include "../Shapes/vertex.h"

namespace Rendering
{
    struct LayouteElement
    {
        uint8_t normolized;
        uint32_t count;
        uint32_t size;

        inline static uint32_t GetTypeSize(uint32_t type)
        {
            switch (type)
            {
            case GL_INT:
                return sizeof(GLint);
            case GL_FLOAT:
                return sizeof(GLfloat);
            case GL_UNSIGNED_INT:
                return sizeof(GLuint);
            case GL_UNSIGNED_BYTE:
                return sizeof(GLubyte);
            }
            ASSERT(false);
            return -1;
        }
    };

    class BufferLayout
    {
    public:
        BufferLayout() : _stride{}, _layouts{} {};
        ~BufferLayout(){};

        inline uint32_t getStride() const { return _stride; };

        inline const std::vector<LayouteElement> &getElements() const { return _layouts; };

        template <typename T>
        void Push(uint32_t count);

    private:
        uint32_t _stride;
        std::vector<LayouteElement> _layouts;
    };

} // namespace Rensering
