#include <iostream>
#include <vector>

class Square;
class Circle;
class Rectangle;

class Visitor {
public:
    virtual void visit(Square& square) = 0;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
};

class Shape {
public:
    virtual void accept(Visitor& visitor) = 0;
};

class Square : public Shape {
private:
    double m_side;

public:
    Square(double side) : m_side(side) {}

    double area() const { return m_side * m_side; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    double getM_side() { return m_side; }
};

class Circle : public Shape {
private:
    double m_radius;

public:
    Circle(double radius) : m_radius(radius) {}

    double area() const { return 3.14159265359 * m_radius * m_radius; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    double getM_radius() { return m_radius; }
};

class Rectangle : public Shape {
private:
    double m_width;
    double m_height;

public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}

    double area() const { return m_width * m_height; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    double getM_width() { return m_width; }
    double getM_height() { return m_height; }
};

class PerimeterVisitor : public Visitor {
private:
    double m_perimeter = 0.0;

public:
    void visit(Square& square) override { m_perimeter += 4 * square.getM_side(); }
    void visit(Circle& circle) override { m_perimeter += 2 * 3.14159265359 * circle.getM_radius(); }
    void visit(Rectangle& rectangle) override { m_perimeter += 2 * (rectangle.getM_width() + rectangle.getM_height()); }
    double perimeter() const { return m_perimeter; }
};

class DrawVisitor : public Visitor {
private:
    void drawSquare(double side) {
        int integerSide = (int)side;
        for (int i = 0; i < integerSide; i++) {
            for (int j = 0; j < integerSide; j++) std::cout << "* ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        figuresDrawed++;
    }

    void drawCircle(double radius) {
        std::cout << "Drawing Circle" << std::endl << std::endl;
        figuresDrawed++;
    }

    void drawRectangle(double width, double height) {
        int integerWidth = (int)width;
        int integerHeight = (int)height;
        for (int i = 0; i < integerHeight; i++) {
            for (int j = 0; j < integerWidth; j++) std::cout << "* ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        figuresDrawed++;
    }

    static int figuresDrawed;

public:
    void visit(Square& square) override { drawSquare(square.getM_side()); }
    void visit(Circle& circle) override { drawCircle(circle.getM_radius()); }
    void visit(Rectangle& rectangle) override { drawRectangle(rectangle.getM_width(), rectangle.getM_height()); }

    int GetCountOfDrawedFigures() { return figuresDrawed; }
};

int DrawVisitor::figuresDrawed = 0;

int main() {
    std::vector<Shape*> shapes = { new Square(3), new Circle(2), new Rectangle(4, 5) };

    PerimeterVisitor perimeterVisitor;
    DrawVisitor drawVisitor;

    for (auto shape : shapes) {
        shape->accept(perimeterVisitor);
        shape->accept(drawVisitor);
    }
    std::cout << "Total perimeter: " << perimeterVisitor.perimeter() << "\n";
    std::cout << "Figures drawed: " << drawVisitor.GetCountOfDrawedFigures() << "\n";

    for (auto shape : shapes) delete shape;
}