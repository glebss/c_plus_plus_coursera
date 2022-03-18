#include <vector>
// #include <iostream>


void Reverse(std::vector<int>& v) {
    for (int i=0; i < v.size() / 2; ++i) {
        int tmp = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = tmp;
    }
}

// int main() {
//     std::vector<int> v = {1, 2, 3, 4, 5};
//     Reverse(v);
//     for (auto el : v) {
//         std::cout << el << " ";
//     }
//     return 0;
// }