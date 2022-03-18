#include <iostream>
#include <string>
#include <map>

bool isAnagrams(std::string& word1, std::string& word2) {
    std::map<char, int> m1, m2;
    for (auto& c : word1) {
        m1[c] += 1;
    }
    for (auto& c : word2) {
        m2[c] += 1;
    }
    return m1 == m2;
}


int main() {
    int n;
    std::cin >> n;
    std::string word1, word2;
    for (int i=0; i < n; ++i) {
        std::cin >> word1 >> word2;
        if (isAnagrams(word1, word2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
        
    }

    return 0;
}