#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::string surname;
    int day;
    int month;
    int year;
};



int main() {
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i=0; i < n; ++i) {
        std::string name, surname;
        int day, month, year;
        std::cin >> name >> surname >> day >> month >> year;
        students[i] = {name, surname, day, month, year};
    }
    int m;
    std::cin >> m;
    for (int j=0; j < m; ++j) {
        std::string operation;
        int k;
        std::cin >> operation >> k;
        if (operation == "name" && k < n+1 && k > 0) {
            Student student = students[k-1];
            std::cout << student.name << " " << student.surname << std::endl;
        } else if (operation == "date" && k < n+1 && k > 0) {
            Student student = students[k-1];
            std::cout << student.day << "." << student.month << "." << student.year << std::endl;
        } else {
            std::cout << "bad request" << std::endl;
        }
    }
    return 0;
}