#include "shader.h"

#include <sstream>
#include <fstream>
#include <filesystem>

namespace Rendering
{
    Shader::Shader() : _id{}, _uniforms_hash(){}

    Shader::~Shader()
    {
        glDeleteProgram(_id);
    }

    Shader* Shader::BuildShader(const std::string& ver, const std::string& frag)
    {
        Shader* sh = new Shader();
        std::string ver_source = sh->getShaderSource(ver);
        uint32_t ver_id = sh->compileShader(GL_VERTEX_SHADER, ver_source);

        std::string frag_source = sh->getShaderSource(frag);
        uint32_t frag_id = sh->compileShader(GL_FRAGMENT_SHADER, frag_source);

        sh->_id = glCreateProgram();
        glAttachShader(sh->_id, ver_id);
        glAttachShader(sh->_id, frag_id);
        glLinkProgram(sh->_id);

        int success;
        glGetProgramiv(sh->_id, GL_LINK_STATUS, &success);

        if (!success)
        {
            std::cerr << "shader-> compile error";
            ASSERT(false);
        }

        glDeleteShader(ver_id);
        glDeleteShader(frag_id);

        return sh;
    }

    void Shader::bind() const {
        GLCHECK(glUseProgram(_id));
    }

    void Shader::unbind() const {
        glUseProgram(0);
    }

    void Shader::setUniform_m4f(const std::string& name, glm::mat4 value){
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void Shader::setUniform_m3f(const std::string& name, glm::mat3 value){
        glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void Shader::setUniform_v3f(const std::string& name, glm::vec3 value){
        glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
    }

    void Shader::setUniform_f(const std::string& name, float value){
        glUniform1f(getUniformLocation(name), value);
    }


    void Shader::setUniform_i(const std::string& name, int32_t value){
        glUniform1i(getUniformLocation(name), value);
    }

    std::string Shader::getShaderSource(const std::string& path) const{
        std::string tmp;
        std::stringstream res;
        std::ifstream stream(path);
        while(getline(stream, tmp)){
            res << tmp <<'\n';
        }
        return res.str();
    }

    uint32_t Shader::compileShader(uint32_t type, const std::string& source){
        uint32_t id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, 0);
        glCompileShader(id);

        int success;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        char log[512];
        if(!success){
            glGetShaderInfoLog(id, 512, nullptr, log);
            std::cerr << "shader-> compile error: "<< log;
            switch(type){
                case GL_VERTEX_SHADER:
                    std::cerr << " --->vertex" << std::endl;
                    break;
                case GL_FRAGMENT_SHADER:
                    std::cerr << " --->fragment" << std::endl;
                    break;
            }
        }

        return id;
    }

    int Shader::getUniformLocation(const std::string& name){
        bind();
        if(_uniforms_hash.find(name) != _uniforms_hash.end()){
            return _uniforms_hash[name];
        }
        int loc = glGetUniformLocation(_id, name.c_str());
        if(-1 == loc){
            std::cerr << "shader-> warning, uniform " << name << " is not exist"
            << std::endl;
        }
        _uniforms_hash[name] = loc;
        return loc;
    }
} // namespace Rendering
