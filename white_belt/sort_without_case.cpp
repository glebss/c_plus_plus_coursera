#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


bool compare(std::string l, std::string r) {
        for (auto& el : l) {
            el = tolower(el);
        }
        for (auto& el : r) {
            el = tolower(el);
        }
        return l < r;
    }

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i=0; i < n; ++i) {
        std::cin >> v[i];
    }
    
    std::sort(v.begin(), v.end(), compare);
    for (const auto& el : v) {
        std::cout << el << " ";
    }
    return 0;
}