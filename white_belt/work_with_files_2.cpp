#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    if (input.is_open()) {
        std::string line;
        while (getline(input, line)) {
            output << line << std::endl;
        }

    }
    return 0;
}