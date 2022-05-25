#include "static_renderable.h"
#include "buffer_layout.h"

namespace Rendering
{
    StaticRenderable::StaticRenderable(const Shapes::RendShape& mesh)
        : _obj{mesh} {}

    StaticRenderable::~StaticRenderable(){
        delete _vArray;
        delete _vBuff;
        delete _iBuff;
        delete _shader;
    }

    StaticRenderable StaticRenderable::Create(const Shapes::RendShape& mesh){
        StaticRenderable sr(mesh);
        sr._vArray = new VertexArray();
        sr._vBuff = new VertBufferStatic(mesh.getVertData(), mesh.getVertSize());
        sr._iBuff = new IndexBufferStatic(mesh.getIndicesData(), mesh.getIndicesCount());
        auto buffLayout = new BufferLayout();
        buffLayout->Push<Shapes::Vertex>(0);

        sr._vArray->addBuffer(*sr._vBuff, *buffLayout);
        delete buffLayout;

        sr._shader = Shader::BuildShader("../res/shaders/vertex.glsl", "../res/shaders/fragment.glsl");

        return sr;
    }

    void StaticRenderable::Render() const{
        _shader->bind();
        _vArray->bind();
        glDrawElements(GL_TRIANGLES, _obj.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
        _vArray->unbind();
        _shader->unbind();
    }

} // namespace Rendering
