#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream input("input.txt");
    std::cout << std::fixed << std::setprecision(3);
    double a;
    while (input >> a) {
        std::cout << a << std::endl;
    }
   
    return 0;
}