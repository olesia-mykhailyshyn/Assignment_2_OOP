#include "iostream"

enum class ShapeType {
    Triangle,
    Rectangle,
    Circle,
    Line,
    Invalid
};

ShapeType stringToShapeType(const std::string& shapeName);