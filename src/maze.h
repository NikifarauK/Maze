#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <exception>
#include <string>
#include <functional>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#define _DEBUG 1


#if _DEBUG
#define ASSERT(x) if(!(x)) asm("int $3");
#else
#define ASSERT(x) x
#endif
