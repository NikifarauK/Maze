#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <exception>
#include <string>
#include <functional>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <stb_image.h>
#include <GLFW/glfw3.h>



#ifdef _DEBUG
#ifdef WINDOWS

#define ASSERT(x) if(!(x)) __debugbreak();
#else
#define ASSERT(x) if(!(x)) {std::cerr << "!--->ASSERT!!!"; asm("int $3");}
#endif // WINDOWS

#define GLCHECK(x) glClearError();\
x;\
ASSERT(glLogCall(#x))

#else
#define ASSERT(x) x
#define GLCHECK(x) x
#endif //_DEBUG

bool glLogCall(const char* func);
void glClearError();
