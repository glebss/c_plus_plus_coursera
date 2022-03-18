#include <string>
#include <vector>

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

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
    std::vector<std::string> res;
    for (int i=0; i != words.size(); ++i) {
        if (words[i].size() >= minLength && IsPalindrom(words[i])) {
            res.push_back(words[i]);
        }
    }
    return res;
}