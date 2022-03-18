#include <string>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
  void AddString(const std::string& s) {
    vec.push_back(s);
    std::sort(vec.begin(), vec.end());
  }
  std::vector<std::string> GetSortedStrings() {
    return vec;
  }
private:
  std::vector<std::string> vec;
};
