#include <string>
#include <map>
#include <iostream>
#include <algorithm>


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
private:
  std::map<int, std::string> map_name;
  std::map<int, std::string> map_surname;
};

// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     std::cout << person.GetFullName(year) << std::endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     std::cout << person.GetFullName(year) << std::endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     std::cout << person.GetFullName(year) << std::endl;
//   }
  
//   return 0;
// }