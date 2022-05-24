#include "cube.h"

namespace Shapes
{
    Cube::Cube(glm::vec3 pos, float side) : 
    _position{pos}, _side{side}
    {
        _vertices ={
            {pos.x + (0.0f * side), pos.y + (0.0f * side), pos.z + (0.0f * side), 0.0f, 0.0f}, //0
            {pos.x + (1.0f * side), pos.y + (0.0f * side), pos.z + (0.0f * side), 1.0f, 0.0f}, //1
            {pos.x + (1.0f * side), pos.y + (1.0f * side), pos.z + (0.0f * side), 1.0f, 1.0f}, //2
            {pos.x + (0.0f * side), pos.y + (1.0f * side), pos.z + (0.0f * side), 0.0f, 1.0f}, //3

            {pos.x + (1.0f * side), pos.y + (0.0f * side), pos.z + (1.0f * side), 0.0f, 0.0f}, //4
            {pos.x + (0.0f * side), pos.y + (0.0f * side), pos.z + (1.0f * side), 1.0f, 0.0f}, //5
            {pos.x + (0.0f * side), pos.y + (1.0f * side), pos.z + (1.0f * side), 1.0f, 1.0f}, //6
            {pos.x + (1.0f * side), pos.y + (1.0f * side), pos.z + (1.0f * side), 0.0f, 1.0f}, //7
            
            {pos.x + (1.0f * side), pos.y + (0.0f * side), pos.z + (1.0f * side), 1.0f, 1.0f}, //8 (4)
            {pos.x + (0.0f * side), pos.y + (0.0f * side), pos.z + (1.0f * side), 0.0f, 1.0f}, //9 (5)
            
            {pos.x + (0.0f * side), pos.y + (1.0f * side), pos.z + (1.0f * side), 0.0f, 0.0f}, //10 (6)
            {pos.x + (1.0f * side), pos.y + (1.0f * side), pos.z + (1.0f * side), 1.0f, 0.0f}, //11 (7)
        };

        _indices = {
            0, 1, 2,  2, 3, 0, //front
            1, 4, 7,  7, 2, 1, //rigth
            4, 5, 6,  6, 7, 4, //back
            5, 0, 3,  3, 6, 5, //left
            3, 2,11, 11,10, 3, //top
            9, 8, 1,  1, 0, 9, //down
        };
    };

} // namespace Shapes
