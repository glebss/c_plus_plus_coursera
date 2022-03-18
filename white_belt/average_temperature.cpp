#include <vector>
#include <iostream>


int main() {
    int n;
    
    int res = 0;
    int sum = 0;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& v: vec) {
        std::cin >> v;
        sum += v;
    }
    double m = double(sum) / n;
    for (auto el : vec) {
        if (el > m) {
            ++res;
        }
    }
    std::cout << res << std::endl;
    for (int j=0; j < n; ++j) {
        if (vec[j] > m) {
            std::cout << j << " ";
        }
    }
    return 0;
}