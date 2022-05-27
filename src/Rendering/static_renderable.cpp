#include "static_renderable.h"
#include "buffer_layout.h"
#include "../helpers.h"

namespace Rendering
{
    StaticRenderable::StaticRenderable()
        : _vArray{}, _vBuff{}, _iBuff{}, _shader{}, _texture{} {}

    StaticRenderable::~StaticRenderable(){
        delete _vArray;
        delete _vBuff;
        delete _iBuff;
        delete _shader;
    }

    StaticRenderable* StaticRenderable::Create(const Shapes::RendShape& mesh, std::shared_ptr<Texture> tex){
        auto sr = new StaticRenderable();
        sr->_vArray = new VertexArray();
        sr->_vBuff = new VertBufferStatic(mesh.getVertData(), mesh.getVertSize());
        sr->_iBuff = new IndexBufferStatic(mesh.getIndicesData(), mesh.getIndicesCount());
        BufferLayout buffLayout;
        buffLayout.Push<Shapes::Vertex>(0);

        sr->_vArray->addBuffer(*sr->_vBuff, buffLayout);

        auto str = Helpers::parent_path();
        if(!tex){
            sr->_shader = Shader::BuildShader(str + "/../res/shaders/vertex.glsl",
             str + "/../res/shaders/fragment.glsl");
        }
        else{
            sr->_texture = tex; 
            sr->_shader =Shader::BuildShader(str + "/../res/shaders/vertex.glsl",
             str + "/../res/shaders/fragment_tex.glsl");
            sr->_texture->bind();
            sr->_shader->setUniform_i("u_Tex", sr->_texture->getSlot());
            sr->_texture->unbind();
        }           

        return sr;
    }

    void StaticRenderable::Render() const{
        _shader->bind();
        _vArray->bind();
        if(_texture)_texture->bind();
        GLCHECK(glDrawElements(GL_TRIANGLES, _iBuff->getCount(), GL_UNSIGNED_INT, 0));
        if(_texture)_texture->unbind();
        _vArray->unbind();
        _shader->unbind();
    }

} // namespace Rendering
