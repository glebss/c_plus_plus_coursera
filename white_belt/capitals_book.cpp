#include <iostream>
#include <map>
#include <string>


int main() {
    std::map<std::string, std::string> capitals_map;
    int q;
    std::cin >> q;
    for (int i=0; i < q; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "CHANGE_CAPITAL") {
            std::string country, new_capital;
            std::cin >> country >> new_capital;
            if (capitals_map.count(country) == 0) {
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
                capitals_map[country] = new_capital;
            } else {
                if (capitals_map[country] == new_capital) {
                    std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
                } else {
                    std::cout << "Country " << country << " has changed its capital from " << capitals_map[country] << " to " << new_capital << std::endl;
                    capitals_map[country] = new_capital;
                }
            }
        } else if (op == "RENAME") {
            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || 
                capitals_map.count(old_country_name) == 0 || 
                capitals_map.count(new_country_name) == 1) {
                    std::cout << "Incorrect rename, skip" << std::endl;
            } else {
                std::cout << "Country " << old_country_name << " with capital " << capitals_map[old_country_name] << " has been renamed to " << new_country_name << std::endl;
                capitals_map[new_country_name] = capitals_map[old_country_name];
                capitals_map.erase(old_country_name);
            }
        } else if (op == "ABOUT") {
            std::string country;
            std::cin >> country;
            if (capitals_map.count(country) == 0) {
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            } else {
                std::cout << "Country " << country << " has capital " << capitals_map[country] << std::endl;
            }
        } else {
            if (capitals_map.size() == 0) {
                std::cout << "There are no countries in the world" << std::endl;
            } else {
                for (const auto& item : capitals_map) {
                    std::cout << item.first << "/" << item.second << std::endl;
                }
            }
        }
    }
    return 0;
}