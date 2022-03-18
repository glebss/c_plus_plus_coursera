#include <iostream>
#include <cmath>


int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    if (a == 0) { 
        if (b != 0) {
            std::cout << -c / b << std::endl;
        }
    } else {
        if (b == 0 && c == 0) {
            std::cout << 0.0 << std::endl;
        } else {
            double d = b*b - 4*a*c;
        if (d == 0) {
            std::cout << -b / (2*a) << std::endl;
        } else if (d > 0) {
            std::cout << (-b + std::sqrt(d)) / (2*a) << " " << (-b - std::sqrt(d)) / (2*a) << std::endl;
            }
        }
        
    }
    return 0;
}