#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    int64_t s = 0;
    std::cin >> n;
    std::vector<int> temps(n);
    for (int i=0; i < n; ++ i) {
        std::cin >> temps[i];
        s += temps[i];
    }
    int64_t avg = s / n;
    int k = std::count_if(temps.begin(), temps.end(), [&](int i){return i > avg;});
    std::cout << k << std::endl;
    for (int i=0; i < n; ++i) {
        if (temps[i] > avg) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}