#include <vector>
#include <iostream>

std::vector<int> range(int n) {
    std::vector<int> result;
    for (int i = 0; i < n; ++i) result.push_back(i);
    return result;
}

int main() {
    for (auto num: range(5)) 
        std::cout << num << " ";
    return 0;
}

