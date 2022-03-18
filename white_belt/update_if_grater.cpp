// #include <iostream>

void UpdateIfGreater(int a, int& b) {
    if (a > b) {
        b = a;
    }
}


// int main() {
//     int a = 1;
//     int b = 5;
//     UpdateIfGreater(a, b);
//     std::cout << b << std::endl;
//     return 0;
// }