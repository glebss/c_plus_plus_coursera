#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>


std::string CreateNameWithHistory(std::vector<int>& years_name, std::map<int, std::string>& map_name) {
    if (years_name.size() == 0) {
        return "";
    } else if (years_name.size() == 1) {
        return map_name[years_name.front()];
    }

    std::vector<std::string> prev_names;
    std::string main_name = map_name[years_name.back()];
    for (int i=years_name.size() - 2; i >= 0; --i) {
        std::string cur_name = map_name[years_name[i]];
        if (cur_name == main_name && prev_names.size() == 0) {
            continue;
        }
        prev_names.push_back(map_name[years_name[i]]);
    }
    
    if (prev_names.size() == 0) {
        return main_name;
    }
    std::string res = main_name + " (";
    for (int i=0; i < prev_names.size()-1; ++i) {
        res += prev_names[i] + ", ";
    }
    res += prev_names.back() + ")";
    return res;
}


class Person {
public:
  void ChangeFirstName(int year, const std::string& first_name) {
    map_name[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
    map_surname[year] = last_name;
  }
  std::string GetFullName(int year) {
    std::vector<int> years_name;
    for (const auto& item : map_name) {
        if (item.first <= year) {
            years_name.push_back(item.first);
        }
    }
    std::vector<int> years_surname;
    for (const auto& item : map_surname) {
        if (item.first <= year) {
            years_surname.push_back(item.first);
        }
    }
    
    if (years_name.size() == 0 && years_surname.size() == 0) {
        return "Incognito";
    } else if (years_name.size() == 0 && years_surname.size() > 0) {
        return map_surname[years_surname.back()] + " with unknown first name";
    } else if (years_name.size() > 0 && years_surname.size() == 0) {
        return map_name[years_name.back()] + " with unknown last name";
    } else {
        return map_name[years_name.back()] + " " + map_surname[years_surname.back()];
    }
  }

  std::string GetFullNameWithHistory(int year) {
    std::vector<int> years_name;
    for (const auto& item : map_name) {
        if (item.first <= year) {
            years_name.push_back(item.first);
        }
    }
    std::vector<int> years_surname;
    for (const auto& item : map_surname) {
        if (item.first <= year) {
            years_surname.push_back(item.first);
        }
    }
    if ((years_name.size() <= 1 && years_surname.size() <= 1)) {
        return GetFullName(year);
    }
    std::string res_name = CreateNameWithHistory(years_name, map_name);
    std::string res_surname = CreateNameWithHistory(years_surname, map_surname);
    if (res_name == "") {
        return res_surname + " with unknown first name";
    } else if (res_surname == "") {
        return res_name + " with unknown last name";
    } else {
        return res_name + " " + res_surname;
    }
  }
private:
  std::map<int, std::string> map_name;
  std::map<int, std::string> map_surname;
};

// int main() {
//   using namespace std;
//   Person person;

//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Appolinaria");

//   person.ChangeLastName(1965, "Sergeeva");
//   person.ChangeLastName(1965, "Volkova");
//   person.ChangeLastName(1965, "Volkova-Sergeeva");

//   for (int year : {1964, 1965, 1966}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   return 0;
// }

