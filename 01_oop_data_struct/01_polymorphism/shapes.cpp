#include "shapes.h"
#include <memory>
#include <vector>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(3));
    shapes.push_back(std::make_unique<Rectangle>(2, 4));

    for (auto &shape: shapes) {
        std::cout << "Shape's area: " << shape->area() << std::endl;
    }

    return 0;
}

/*
OUTPUT:

Circle CTOR
Rectangle CTOR
Shape's area: 28.2743
Shape's area: 8
Circle DTOR
Shape DTOR
Rectangle DTOR
Shape DTOR
*/