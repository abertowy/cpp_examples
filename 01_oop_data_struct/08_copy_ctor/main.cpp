# include <iostream>

class Circle {
private:
    int radius;

public:
    // Constructor
    Circle(const int val = 0) {
        std::cout << "Normal constructor called." << std::endl;
    }
    // Copy Constructor (Deep Copy)
    Circle(const Circle& other) {
        radius = other.radius;
        std::cout << "Copy constructor called." << std::endl;
    }
    // Destructor
    ~Circle() {
        std::cout << "Destructor called." << std::endl;
    }
};

int main() {
    Circle c1(10);      // Normal constructor
    Circle c2 = c1;     // Copy constructor (initialization)
    Circle c3(c1);      // Copy constructor (direct initialization)
    return 0;
}
