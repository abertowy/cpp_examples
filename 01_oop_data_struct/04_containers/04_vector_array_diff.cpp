#include <iostream>
#include <vector>

// Task#2
// What is the difference between lines A and B?
void foo(std::vector<int>& vec) {
    vec[0];      // A
    vec.at(0);   // B -> exeption std::out_of_range
}

// Task#3
// What will be the output of this program?
int main() {
    std::vector<int> vec;
    vec.reserve(2);
    vec[0] = 1;
    vec[1] = 2;
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i);
    }
}