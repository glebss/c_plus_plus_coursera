#include <string>
#include <vector>
// #include <iostream>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (auto w : source) {
        destination.push_back(w);
    }
    source.clear();
}

// int main() {
//     std::vector<std::string> source = {"a", "b", "c"};
//     return 0;
// }