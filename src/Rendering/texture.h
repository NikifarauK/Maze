#pragma once

#include "../maze.h"

namespace Rendering
{
    class Texture
    {
    public:
        Texture(const std::string& path);
        ~Texture();
        void bind() const;
        void unbind() const;
        inline int32_t getWidth() const { return _width; };
        inline int32_t getHeiht() const { return _hight; };
        inline int32_t getBPP() const { return _bit_per_pixel; };
        inline uint32_t getSlot() const { return _self_slot; };
    private:
        uint32_t _id, _self_slot;
        int32_t _width, _hight, _bit_per_pixel;
        std::string _filePath;

        static uint32_t s_next_slot;
    };
    
} // namespace Rendering
