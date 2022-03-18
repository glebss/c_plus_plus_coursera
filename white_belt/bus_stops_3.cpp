#include <map>
#include <iostream>
#include <set>
#include <string>

int main() {
    int q;
    std::cin >> q;
    std::map<std::set<std::string>, int> m;
    for (int i=0; i < q; ++i) {
        std::set<std::string> stops;
        int n;
        std::cin >> n;
        for (int j=0; j<n; ++j) {
            std::string stop;
            std::cin >> stop;
            stops.insert(stop);
        }
        if (m.count(stops) > 0) {
            std::cout << "Already exists for " << m[stops] << std::endl;
        } else {
            int old_size = m.size();
            m[stops] = old_size + 1;
            std::cout << "New bus " << m[stops] << std::endl;
        }

    }
    return 0;
}