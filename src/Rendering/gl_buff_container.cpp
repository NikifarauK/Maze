#include "gl_buff_container.h"
#include "buffer_layout.h"

namespace Rendering
{
    std::unordered_map<std::string, std::shared_ptr<GLBuffConteiner>> GLBuffConteiner::s_existed;

    GLBuffConteiner::GLBuffConteiner() : _vArray{}, _vBuff{}, _iBuff{}
    {}

    GLBuffConteiner::~GLBuffConteiner(){
        delete _iBuff;
        delete _vBuff;
        delete _vArray;
    }

    std::shared_ptr<GLBuffConteiner> GLBuffConteiner::Create(const Shapes::RendShape& rs){
        auto& name = rs.getName();
        if(s_existed.find(name) != s_existed.end()){
            return s_existed[name];
        }

        auto gl_buff_c = std::make_shared<GLBuffConteiner>();
        gl_buff_c->_vArray = new VertexArray();
        gl_buff_c->_vBuff = new VertBufferStatic(rs.getVertData(), rs.getVertSize());
        gl_buff_c->_iBuff = new IndexBufferStatic(rs.getIndicesData(), rs.getIndicesCount());
        BufferLayout buffLayout;
        buffLayout.Push<Shapes::Vertex>(0);

        gl_buff_c->_vArray->addBuffer(*gl_buff_c->_vBuff, buffLayout);

        s_existed[name] = gl_buff_c;
        return gl_buff_c;
    }

    void GLBuffConteiner::bind() const{
        _vArray->bind();
    }

    void GLBuffConteiner::unbind()const {
        _vArray->unbind();
    }

} // namespace Rendering
