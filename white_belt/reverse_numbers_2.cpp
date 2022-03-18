#include <vector>
// #include <iostream>

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> b = v;
    for (int i=0; i < v.size(); ++i) {
        b[v.size()-i-1] = v[i];
    }
    return b;
}

// int main() {
//     std::vector<int> v = {1,2,3,4,5};
//     std::vector<int> b = Reversed(v);
//     for (auto el : b) {
//         std::cout << el << " ";
//     }
//     return 0;
// }
