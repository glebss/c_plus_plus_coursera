#pragma once
#include <sstream>
#include <iostream>
using namespace std;

struct Date {
    Date();
    Date(int year, int month, int day);
    int year_;
    int month_;
    int day_;
};

ostream& operator<<(ostream& out, const Date& date);
bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
ostream& operator<<(ostream& out, const pair<Date, string>& p);

Date ParseDate(istream& is);

