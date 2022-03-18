#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

          
int main() {
    std::fstream input("input.txt");
    int n, m;
    input >> n;
    input.ignore(1);
    input >> m;
    input.ignore(1);
    std::cout << std::right;
    for (int i=0; i < n; ++i) {
        std::vector<int> values;
        for (int j=0; j < m; ++j) {
            int v;
            input >> v;
            input.ignore(1);
            std::cout << std::setw(10) << v;
            if (j != m-1) {
                std::cout << " ";
            }
        }
        if (i != n-1) {
            std::cout << std::endl;
        }
    }
    return 0;
}