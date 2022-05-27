#include "texture.h"

namespace Rendering
{
    uint32_t Texture::s_next_slot = 0;

    Texture::Texture(std::string const& path)
        : _id{}, _self_slot{s_next_slot++}, _filePath{path} {
        stbi_set_flip_vertically_on_load(0);

        auto buffer = stbi_load(path.c_str(), &_width, &_hight, &_bit_per_pixel, 4);
        glGenTextures(1, &_id);
        glBindTexture(GL_TEXTURE_2D, _id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _hight, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
        glGenerateMipmap(GL_TEXTURE_2D);

        if(buffer)
            stbi_image_free(buffer);
            unbind();
    }

    Texture::~Texture(){
        glDeleteTextures(1, &_id);
    }

    void Texture::bind() const {
        GLCHECK(glActiveTexture(GL_TEXTURE0 + _self_slot));
        glBindTexture(GL_TEXTURE_2D, _id);
    }

    void Texture::unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}; // namespace Rendering
