#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T, std::size_t N>
class HashMap {
    static const int SIZE = 10;
    std::list<std::pair<int, std::list<std::pair<T, T>>>> table;

public:
    HashMap() : table(N) {}

    void insert(T key, T value) {
        auto item = std::pair<T, T> (key, value);
        int index = key % N;
        auto iter = std::find_if(table.begin(), table.end(), [&index]( auto v ){ return v.first == index; });
        if (table.end() == iter) {
            std::cout << "item not found" << std::endl;
            auto val_list = std::list<std::pair<T, T>> {item};
            table.emplace_back(index, val_list);
        }
        else {
            std::cout << "item found, to be updated " << std::endl;
            std::pair<int, std::list<std::pair<T, T>>> element = *iter;
            iter->second.push_back(item);
        }
    }

    T get(T key) const {
        int index = key % N;
        auto iter = std::find_if(table.begin(), table.end(), [&index]( auto v ){ return v.first == index; });
        if (table.end() == iter) {
            throw std::runtime_error("Key not found");
        }
        else {
            auto values = iter->second;
            auto v_iter = std::find_if(values.begin(), values.end(), [&key]( auto v ){ return v.first == key; });
            return v_iter->second;
        }
    }

    std::vector<T> get_all(T key) const {
        int index = key % N;
        auto iter = std::find_if(table.begin(), table.end(), [&index]( auto v ){ return v.first == index; });
        if (table.end() == iter) {
            throw std::runtime_error("Key not found");
        }
        else {
            std::vector<T> values;
            for (const auto& p : iter->second) {
                if (p.first == key) {
                    values.push_back(p.second);
                }
            }
            return values;
        }
    }
};