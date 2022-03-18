#include <map>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <utility>
using namespace std;

std::string modify(const std::string& s) {
    return s + "aaaa";
}

struct Date {
    Date(int year, int month, int day) {
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
    
    int year_;
    int month_;
    int day_;
};

string ParseEvent(istream& is) {
  string event;
  getline(is, event);
  return event;
}

// Date ParseDate(istream& is) {
//     int year, month, day;
//     is >> year;
//     is.ignore(1);
//     is >> month;
//     is.ignore(1);
//     is >> day;
//     return {year, month, day};
// }

ostream& operator<<(ostream& out, const Date& date) {
    out << date.year_ << "-" << date.month_ << "-" << date.day_;
    return out;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year_ != rhs.year_) {
        lhs.year_ < rhs.year_;
    } else if (lhs.month_ != rhs.month_) {
        return lhs.month_ < rhs.month_;
    }
    return lhs.day_ < rhs.day_;
}

bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.year_ == rhs.year_ && lhs.month_ == rhs.month_ && lhs.day_ == rhs.day_;
}

ostream& operator<<(ostream& out, const pair<Date, string>& p) {
    out << p.first << " " << p.second;
    return out;
}

int main() {
    map<Date, int> a;
    Date date1(2000, 1, 1);
    Date date2(2005, 1, 1);
    cout << (date1 == date2) << endl;
    a[date1] = 1;
    a[date2] = 2;
    cout << a.size() << endl;
    auto upper = a.upper_bound(Date(1999, 1, 1));
    if (upper == a.end()) {
        cout << "End" << endl;
    }
    if (upper == a.begin()) {
        cout << "Begin" << endl;
    }
    // cout << upper->first << endl;
    // cout << upper->first << endl;
    // cout << prev(upper)->first << endl;
    return 0;
}