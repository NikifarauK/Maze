#include <filesystem>
#include "helpers.h"

std::string Helpers::parent_path()
{
#ifdef WINDOWS
	return "..";
#else
	auto t = std::filesystem::canonical("/proc/self/exe");
	return t.parent_path().string();
#endif // WINDOWS
}

std::string Helpers::shader_location(const std::string& file_name) {
#ifdef WINDOWS
	auto str = std::string("..\\res\\shaders\\") + &(file_name.data()[1]);
	return str;
#else
	std::string path = parent_path() + "/../res/shaders" + file_name;
	if (std::filesystem::exists(path))
		return path;
	std::cerr << "!----> No such image: " << file_name << std::endl;
	return "";
#endif // WINDOWS
}

std::string Helpers::image_location(const std::string& file_name) {
#ifdef WINDOWS
	auto str = std::string("..\\res\\img\\") + &(file_name.data()[1]);
	return str;
#else
	std::string path = parent_path() + "/../res/img" + file_name;
	if (std::filesystem::exists(path))
		return path;
	std::cerr << "!----> No such image: " << file_name << std::endl;
	return "";
#endif // WINDOWS
}