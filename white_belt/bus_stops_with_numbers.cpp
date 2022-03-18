#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    int q;
    std::cin >> q;

    int route_number = 1;
    std::map<int, std::vector<std::string>> m;
    for (int i=0; i < q; ++i) {
        bool was = false;
        int n_stops;
        std::cin >> n_stops;
        std::vector<std::string> stops;
        for (int j=0; j < n_stops; ++j) {
            std::string stop;
            std::cin >> stop;
            stops.push_back(stop);
        }
        for (const auto& item : m) {
            if (m[item.first] == stops) {
                std::cout << "Already exists for " << item.first << std::endl;
                was = true;
            }
        }
        if (!was) {
            m[route_number] = stops;
            std::cout << "New bus " << route_number << std::endl;
            ++route_number;
        }
    }
    return 0;
}