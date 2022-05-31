#pragma once 

#include "../maze.h"
#include "vertex_array.h"
#include "vertex_buffer_static.h"
#include "index_buffer_static.h"
#include "../Shapes/renderable_shape.h"

namespace Rendering
{
    class GLBuffConteiner
    {
    public:
        GLBuffConteiner();
        ~GLBuffConteiner();

        static std::shared_ptr<GLBuffConteiner> Create(const Shapes::RendShape&);

        void bind() const;
        void unbind() const;
        inline uint32_t getCount() {return _iBuff->getCount(); };
    private:
        static std::unordered_map<std::string, std::shared_ptr<GLBuffConteiner>> s_existed;
        
        VertexArray *_vArray;
        VertBuffer  *_vBuff;
        IndexBuffer *_iBuff;

        GLBuffConteiner(GLBuffConteiner&)                  = delete;
        GLBuffConteiner(const GLBuffConteiner&)            = delete;
        GLBuffConteiner(GLBuffConteiner&&)                 = delete;
        GLBuffConteiner operator=(GLBuffConteiner const &) = delete;
    };
    
} // namespace Rendering
