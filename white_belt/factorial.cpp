// #include <iostream>

int Factorial(int n) {
    int res = 1;
    if (n <= 0) {
        return 1;
    }
    while (n > 1) {
        res *= n;
        --n;
    }
    return res;
}

// int main() {
//     for (int i=-10; i <=10; ++i) {
//         std::cout << factorial(i) << std::endl;
//     }
    
//     return 0;
// }