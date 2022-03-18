#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;
    // std::vector<std::string> v;
    // v.push_back(s1);
    // v.push_back(s2);
    // v.push_back(s3);
    // std::sort(v.begin(), v.end());
    // std::cout << v[0] << std::endl;
    std::string min_string = s1;
    if (s1 > s2 || s1 > s3) {
        min_string = std::min(s2, s3);
    }
    std::cout << min_string;

    return 0;


}