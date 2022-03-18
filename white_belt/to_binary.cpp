#include <iostream>
#include <vector>
int main() {
    int a;
    std::vector<int> res;
    std::cin >> a;
    while (a != 0) {
        res.push_back(a%2);
        a /= 2;
    }
    for (int i=res.size()-1; i>=0; --i) {
        std::cout << res[i];
    }
    return 0;
}