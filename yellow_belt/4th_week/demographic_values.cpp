#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// enum class Gender {
//   FEMALE,
//   MALE
// };

// struct Person {
//   int age;  // возраст
//   Gender gender;  // пол
//   bool is_employed;  // имеет ли работу
// };



// // Это пример функции, его не нужно отправлять вместе с функцией PrintStats
// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//   if (range_begin == range_end) {
//     return 0;
//   }
//   vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//   auto middle = begin(range_copy) + range_copy.size() / 2;
//   nth_element(
//       begin(range_copy), middle, end(range_copy),
//       [](const Person& lhs, const Person& rhs) {
//         return lhs.age < rhs.age;
//       }
//   );
//   return middle->age;
// }

template<typename Lambda, typename T>
int MedianAgeForGroup(vector<T> vec, Lambda func) {
    auto it = partition(vec.begin(), vec.end(), func);
    return ComputeMedianAge(vec.begin(), it);
}

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    
    cout << "Median age for females = " << 
    MedianAgeForGroup(persons, [](Person& p) {return p.gender == Gender::FEMALE; }) << endl;
    
    cout << "Median age for males = " << 
    MedianAgeForGroup(persons, [](Person& p) {return p.gender == Gender::MALE; }) << endl;

    cout << "Median age for employed females = " << 
    MedianAgeForGroup(persons, [](Person& p) {return p.gender == Gender::FEMALE && p.is_employed; }) << endl;

    cout << "Median age for unemployed females = " << 
    MedianAgeForGroup(persons, [](Person& p) {return p.gender == Gender::FEMALE && !p.is_employed; }) << endl;

    cout << "Median age for employed males = " << 
    MedianAgeForGroup(persons, [](Person& p) {return p.gender == Gender::MALE && p.is_employed; }) << endl;

    cout << "Median age for unemployed males = " << 
    MedianAgeForGroup(persons, [](Person& p) {return p.gender == Gender::MALE && !p.is_employed; }) << endl;

}

// int main() {
//   vector<Person> persons = {
//       {31, Gender::MALE, false},
//       {40, Gender::FEMALE, true},
//       {24, Gender::MALE, true},
//       {20, Gender::FEMALE, true},
//       {80, Gender::FEMALE, false},
//       {78, Gender::MALE, false},
//       {10, Gender::FEMALE, false},
//       {55, Gender::MALE, true},
//   };
//   PrintStats(persons);
//   return 0;
// }
