#include <iostream>


int main() {
    int n, r;
    uint64_t m = 0;
    std::cin >> n >> r;
    for (int i=0; i < n; ++i) {
        int w, h, d;
        std::cin >> w >> h >> d;
        uint64_t V = static_cast<uint64_t>(w)*static_cast<uint64_t>(h)*static_cast<uint64_t>(d);
        m += V*static_cast<uint64_t>(r);
    }
    std::cout << m << std::endl;
    return 0;
}