#include <filesystem>
#include "static_renderable.h"
#include "buffer_layout.h"

namespace Rendering
{
    StaticRenderable::StaticRenderable()
        : _vArray{}, _vBuff{}, _iBuff{}, _shader{} {}

    StaticRenderable::~StaticRenderable(){
        delete _vArray;
        delete _vBuff;
        delete _iBuff;
        delete _shader;
    }

    StaticRenderable* StaticRenderable::Create(const Shapes::RendShape& mesh){
        auto sr = new StaticRenderable();
        sr->_vArray = new VertexArray();
        sr->_vBuff = new VertBufferStatic(mesh.getVertData(), mesh.getVertSize());
        sr->_iBuff = new IndexBufferStatic(mesh.getIndicesData(), mesh.getIndicesCount());
        BufferLayout buffLayout;
        buffLayout.Push<Shapes::Vertex>(0);

        sr->_vArray->addBuffer(*sr->_vBuff, buffLayout);

        auto t = std::filesystem::canonical("/proc/self/exe");
        auto str = t.parent_path().string();
        sr->_shader = Shader::BuildShader(str + "/../res/shaders/vertex.glsl", str + "/../res/shaders/fragment.glsl");

        return sr;
    }

    void StaticRenderable::Render() const{
        _shader->bind();
        _vArray->bind();
        GLCHECK(glDrawElements(GL_TRIANGLES, _iBuff->getCount(), GL_UNSIGNED_INT, 0));
        _vArray->unbind();
        _shader->unbind();
    }

} // namespace Rendering
