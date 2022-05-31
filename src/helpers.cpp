#include <filesystem>
#include "helpers.h"

std::string Helpers::parent_path()
{
    auto t = std::filesystem::canonical("/proc/self/exe");
    return t.parent_path().string();
}

std::string Helpers::shader_location(const std::string& file_name){
    std::string path = parent_path() + "/../res/shaders" + file_name;
    if(std::filesystem::exists(path))
        return path;
    std::cerr << "!----> No such image: " << file_name << std::endl;
    return "";
}

std::string Helpers::image_location(const std::string& file_name){
    std::string path = parent_path() + "/../res/img" + file_name;
    if(std::filesystem::exists(path))
        return path;
    std::cerr << "!----> No such image: " << file_name << std::endl;
    return "";
}