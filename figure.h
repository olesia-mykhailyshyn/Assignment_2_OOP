#pragma once
#include <string>

class Board;

class Figure {
public:
    virtual void draw(Board& board) = 0;
    [[nodiscard]] virtual std::string getInfo() const = 0;
    [[nodiscard]] virtual std::string getSaveFormat() const = 0;
    [[nodiscard]] virtual bool isOutOfBounds(int boardWidth, int boardHeight) const = 0;
    virtual ~Figure() = default;
};

class Triangle : public Figure {
public:
    explicit Triangle(int x, int y, int height) : x(x), y(y), height(height) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int x, y, height;
};

class Rectangle : public Figure {
public:
    friend class Board;
    explicit Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int x, y, width, height;
};

class Circle : public Figure {
public:
    explicit Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int x, y, radius;
};

class Line : public Figure {
public:
    explicit Line(int x, int y, int size) : x(x), y(y), size(size){}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int x, y, size;
};