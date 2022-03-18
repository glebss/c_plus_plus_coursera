#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    int n_occ = std::count(s.begin(), s.end(), 'f');
    if (n_occ == 0) {
        std::cout << -2 << std::endl;
    }
    else if (n_occ == 1) {
        std::cout << -1 << std::endl;
    }
    else {
        bool was = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'f') {
                if (was) {
                    std::cout << i << std::endl;
                    break;
                }
                else {
                    was = true;
                }
            }
        }        
    }
    return 0;
}