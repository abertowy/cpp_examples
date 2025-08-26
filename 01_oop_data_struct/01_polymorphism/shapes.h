#include <iostream>

class Shape {
public:
    virtual ~Shape() {std::cout << "Shape DTOR" << std::endl;}
    virtual double area() const = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) { std::cout << "Circle CTOR" << std::endl; }
    ~Circle() { std::cout << "Circle DTOR" << std::endl; }
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) { std::cout << "Rectangle CTOR" << std::endl; }
    ~Rectangle() { std::cout << "Rectangle DTOR" << std::endl; }
    double area() const override { return width * height; }
};