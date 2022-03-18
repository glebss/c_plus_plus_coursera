#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// class Person {
// public:
//   void ChangeFirstName(int year, const std::string& first_name) {
//     map_name[year] = first_name;
//   }
//   void ChangeLastName(int year, const std::string& last_name) {
//     map_surname[year] = last_name;
//   }
//   std::string GetFullName(int year) {
//     std::vector<int> years_name;
//     for (const auto& item : map_name) {
//         if (item.first <= year) {
//             years_name.push_back(item.first);
//         }
//     }
//     std::vector<int> years_surname;
//     for (const auto& item : map_surname) {
//         if (item.first <= year) {
//             years_surname.push_back(item.first);
//         }
//     }
    
//     if (years_name.size() == 0 && years_surname.size() == 0) {
//         return "Incognito";
//     } else if (years_name.size() == 0 && years_surname.size() > 0) {
//         return map_surname[years_surname.back()] + " with unknown first name";
//     } else if (years_name.size() > 0 && years_surname.size() == 0) {
//         return map_name[years_name.back()] + " with unknown last name";
//     } else {
//         return map_name[years_name.back()] + " " + map_surname[years_surname.back()];
//     }
//   }
// private:
//   std::map<int, std::string> map_name;
//   std::map<int, std::string> map_surname;
// };

void TestPerson() {
    Person person;
    string res;
    
    res = person.GetFullName(1900);
    AssertEqual(res, "Incognito", "Incognito when no history");

    person.ChangeFirstName(1980, "Ivan");
    res = person.GetFullName(1977);
    AssertEqual(res, "Incognito", "Incognito when no changes up to year");
    
    res = person.GetFullName(1980);
    AssertEqual(res, "Ivan with unknown last name", "First name with unknown last");

    person.ChangeLastName(1975, "Ivanov");
    res = person.GetFullName(1975);
    AssertEqual(res, "Ivanov with unknown first name", "Last name with unknown first");

    res = person.GetFullName(1980);
    AssertEqual(res, "Ivan Ivanov", "First and Last name");

    person.ChangeFirstName(1981, "Petr");
    res = person.GetFullName(1981);
    AssertEqual(res, "Petr Ivanov", "First name change and Last name");

    person.ChangeLastName(1982, "Petrov");
    res = person.GetFullName(1982);
    AssertEqual(res, "Petr Petrov", "First name and Last name change");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestPerson, "TestPerson");
  return 0;
}