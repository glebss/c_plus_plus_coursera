#include <set>
#include <iostream>
#include <string>

int main() {
    std::set<std::string> s;
    int q;
    std::cin >> q;
    for (int i=0; i < q; ++i) {
        std::string string;
        std::cin >> string;
        s.insert(string);

    }
    std::cout << s.size() << std::endl;

    return 0;
}