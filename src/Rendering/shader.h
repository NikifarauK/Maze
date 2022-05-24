#pragma once

#include <unordered_map>

#include "../maze.h"

namespace Rendering
{
    class Shader
    {
    public:
        ~Shader();
        static Shader BuildShader(const std::string& ver, const std::string&);
        void bind() const;
        void unbind() const;

        void setUniform_m4f(const std::string&, glm::mat4);
        void setUniform_v3f(const std::string&, glm::vec3);
        void setUniform_f(const std::string&, float);
        void setUniform_i(const std::string&, int);

    protected:
        std::string getShaderSource(const std::string& path) const;
        uint32_t compileShader(uint32_t, const std::string&);
        int getUniformLocation(const std::string&);

        Shader();//move to private
    private:
        uint32_t _id;
        std::unordered_map<std::string, int32_t>* _p_uniforms_hash;
    };

    
} // namespace Rendering
