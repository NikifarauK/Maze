#pragma once

#include <unordered_map>

#include "../maze.h"

namespace Rendering
{
    class Shader
    {
    public:
        ~Shader();
        static Shader* BuildShader(const std::string& ver, const std::string& frag);
        void bind() const;
        void unbind() const;

        void setUniform_m4f(const std::string&, glm::mat4);
        void setUniform_m3f(const std::string&, glm::mat3);
        void setUniform_v3f(const std::string&, glm::vec3);
        void setUniform_f(const std::string&, float);
        void setUniform_i(const std::string&, int32_t);

    protected:
        std::string getShaderSource(const std::string& path) const;
        uint32_t compileShader(uint32_t, const std::string&);
        int getUniformLocation(const std::string&);

    private:
        Shader();
        // Shader(const Shader&) = delete;
        // Shader(Shader&) = delete;
        // Shader(Shader&&) = delete;
        uint32_t _id;
        std::unordered_map<std::string, int32_t> _uniforms_hash;
    };

    
} // namespace Rendering
