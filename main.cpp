#include <iostream>
#include <vector>
#include <chrono>

void slow_function(std::vector<int>& data) {
    for (auto& val : data) {
        for (int i = 0; i < 1000; ++i) {
            val += i;
        }
    }
}

void optimized_function(std::vector<int>& data) {
    for (auto& val : data) {
        val += (999 * 1000) / 2;
    }
}

int main() {
    std::vector<int> data(100000, 1);
    
    auto start = std::chrono::high_resolution_clock::now();
    slow_function(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Slow function time: " << diff.count() << " s\n";
    
    start = std::chrono::high_resolution_clock::now();
    optimized_function(data);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Optimized function time: " << diff.count() << " s\n";
    
    return 0;
}
