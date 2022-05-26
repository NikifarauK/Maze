#include "maze.h"

void glClearError(){
    while(glGetError());
}

bool glLogCall(const char* func){
    while(GLenum error = glGetError()){
        std::cerr << "OpenGL error--> (" << error 
        << ") " << func << std::endl;
        return false;
    }
    return true;
}