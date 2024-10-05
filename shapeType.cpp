#include "shapeType.h"

ShapeType stringToShapeType(const std::string& shapeName) {
    if (shapeName == "triangle") return ShapeType::Triangle;
    if (shapeName == "rectangle") return ShapeType::Rectangle;
    if (shapeName == "circle") return ShapeType::Circle;
    if (shapeName == "line") return ShapeType::Line;
    return ShapeType::Invalid;
}