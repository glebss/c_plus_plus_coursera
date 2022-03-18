#include <map>
#include <string>
#include <iostream>
#include <vector>
#include<set>

int main() {
    std::map<std::string, std::set<std::string>> m;
    int q;
    std::cin >> q;
    for (int i=0; i<q; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "ADD") {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            m[word1].insert(word2);
            m[word2].insert(word1);

        } else if (op == "COUNT") {
            std::string word;
            std::cin >> word;
            std::cout << m[word].size() << std::endl;
        } else {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            if (m[word1].count(word2) > 0 || m[word2].count(word1) > 0) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}