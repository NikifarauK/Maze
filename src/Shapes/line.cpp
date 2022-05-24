#include "line.h"

Shapes::Line::Line(glm::vec3 point, glm::vec3 direction) noexcept 
    : _point(point), _direction(glm::normalize(direction)) {}

Shapes::Line::~Line(){}

float Shapes::Line::getDistanceToPoint(glm::vec3 other_point){
    return glm::length(glm::cross(_point - other_point, _direction));
}