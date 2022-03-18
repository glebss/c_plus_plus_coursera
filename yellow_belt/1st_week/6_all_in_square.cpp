#include <map>
#include <vector>
#include <utility>
#include <iostream>

template<typename T> T Sqr(T& a);
template<typename T> std::vector<T> Sqr(std::vector<T>& vec);
template<typename Key, typename Value> std::map<Key, Value> Sqr(std::map<Key, Value>& m);
template<typename First, typename Second> std::pair<First, Second> Sqr(std::pair<First, Second>& p);


template<typename T>
T Sqr(T& a) {
    return a * a;
}

template<typename T>
std::vector<T> Sqr(std::vector<T>& vec) {
    for (auto& el : vec) {
        el = Sqr(el);
    }
    return vec;
}

template<typename Key, typename Value>
std::map<Key, Value> Sqr(std::map<Key, Value>& m) {
    for (auto& item : m) {
        m[item.first] = Sqr(item.second);
    }
    return m;
}

template<typename First, typename Second>
std::pair<First, Second> Sqr(std::pair<First, Second>& p) {
    return std::make_pair(Sqr(p.first), Sqr(p.second));
}

// int main() {
//     using namespace std;
//     vector<int> v = {1, 2, 3};
//     vector<vector<int>> v = {{1, 2}, {3, 5}};
//     cout << "vector:";
//     v = Sqr(v);
//     for (auto x : Sqr(v)) {
//     cout << ' ' << x;
//     }
//     cout << endl;
//     map<int, int> m = {{1,2}, {2, 5}};
//     cout << "map:" << endl;
//     for (const auto& x : Sqr(m)) {
//         cout << x.first << " " << x.second << endl;
//     }
//     map<int, pair<int, int>> map_of_pairs = {
//     {4, {2, 2}},
//     {7, {4, 3}}
//     };
//     cout << "map of pairs:" << endl;
//     for (const auto& x : Sqr(map_of_pairs)) {
//     cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//     }
//     return 0;
// }