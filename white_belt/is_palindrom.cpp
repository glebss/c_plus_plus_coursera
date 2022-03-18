#include <string>
// #include <iostream>
// #include <vector>

bool IsPalindrom(std::string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i++ < j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

// int main() {
//     std::vector<std::string> v;
//     v.push_back("madam");
//     v.push_back("x");
//     v.push_back("lalalala");
//     v.push_back("");
//     for (int i =0; i != v.size(); ++i) {
//         std::cout << IsPalindrom(v[i]) << std::endl;
//     }

//     return 0;
// }