#include <map>
#include <string>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> s;
    for (const auto& item : m) {
        s.insert(item.second);
    }
    return s;

}