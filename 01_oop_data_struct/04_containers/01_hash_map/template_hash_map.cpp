#include "template_hash_map.h"

int main() {
    HashMap<int, 10> map;
    map.insert(1, 100);
    map.insert(11, 200);
    map.insert(11, 300);
    std::cout << "Get results: " << map.get(1) << " " << map.get(11) << std::endl;
    std::cout << "Get ALL results: ";
    for (auto v: map.get_all(11)) {
        std::cout << v << " ";
    }
    return 0;
}

/*
item not found
item found, to be updated 
item found, to be updated 
Get results: 100 200
Get ALL results: 200 300 
*/