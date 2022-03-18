#include "date.h"
#include <stdexcept>
#include <iomanip>
using namespace std;


Date::Date() {}
Date::Date(int year, int month, int day) {
    if (year < 0 || year > 9999) {
        throw runtime_error("year value is invalid");
    }
    if (month < 1 || month > 12) {
        throw runtime_error("month value is invalid");
    }
    if (day < 1 || day > 31) {
        throw runtime_error("day value is invalid");
    }
    year_ = year;
    month_ = month;
    day_ = day;
}
    

ostream& operator<<(ostream& out, const Date& date) {
    out << setfill('0') << setw(4) << date.year_ << "-" 
        << setw(2) << date.month_ << "-" << setw(2) << date.day_;
    return out;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year_ != rhs.year_) {
        return lhs.year_ < rhs.year_;
    } else if (lhs.month_ != rhs.month_) {
        return lhs.month_ < rhs.month_;
    }
    return lhs.day_ < rhs.day_;
}

ostream& operator<<(ostream& out, const pair<Date, string>& p) {
  out << p.first << " " << p.second;
  return out;
}

bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.year_ == rhs.year_ && lhs.month_ == rhs.month_ && lhs.day_ == rhs.day_;
}

Date ParseDate(istream& is) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    return {year, month, day};
}