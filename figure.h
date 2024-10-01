#pragma once
#include <string>

class Board;

class Figure {
public:
    virtual void draw(Board& board) = 0;
    [[nodiscard]] virtual std::string getInfo() const = 0;
    [[nodiscard]] virtual std::string getSaveFormat() const = 0;
    [[nodiscard]] virtual bool isOutOfBounds(int boardWidth, int boardHeight) const;
    virtual ~Figure() = default;

protected:
    int x, y;

    Figure(int x, int y) : x(x), y(y) {}

    static bool isPositionOutOfBounds(int x, int y, int boardWidth, int boardHeight) {
        return x < 0 || y < 0 || x >= boardWidth || y >= boardHeight;
    }

    //friend class Board;
};

class Triangle : public Figure {
public:
    explicit Triangle(int x, int y, int height) : Figure(x, y), height(height) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int height;
};

class Rectangle : public Figure {
public:
    explicit Rectangle(int x, int y, int width, int height) : Figure(x, y), width(width), height(height) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int width, height;
};

class Circle : public Figure {
public:
    explicit Circle(int x, int y, int radius) : Figure(x, y), radius(radius) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int radius;
};

class Line : public Figure {
public:
    explicit Line(int x, int y, int size) : Figure(x, y), size(size) {}
    void draw(Board& board) override;
    [[nodiscard]] std::string getInfo() const override;
    [[nodiscard]] std::string getSaveFormat() const override;
    [[nodiscard]] bool isOutOfBounds(int boardWidth, int boardHeight) const override;

private:
    int size;
};