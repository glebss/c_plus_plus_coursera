#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

template<typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, const Key k) {
    if (m.count(k) == 0) {
        throw std::runtime_error("");
    }
    return m[k];
}

// int main() {
//     using namespace std;
//     map<int, string> m = {{0, "value"}};
//     string& item = GetRefStrict(m, 0);
//     item = "newvalue";
//     cout << m[0] << endl; // выведет newvalue
//     return 0;
// }