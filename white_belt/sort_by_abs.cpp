#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i=0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::sort(numbers.begin(), numbers.end(), [](int x, int y) {return abs(x) < abs(y); });
    for (const auto& i : numbers) {
        std::cout << i << " ";
    }
    return 0;
}