#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <chrono>
#include <numeric>
using namespace std;

struct Date {
    Date() {}
    Date(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }
    int year_;
    int month_;
    int day_;
};

time_t AsTimestamp(const Date& date) {
    
    tm t;
    t.tm_sec  = 0;
    t.tm_min  = 0;
    t.tm_hour = 0;
    t.tm_mday = date.day_;
    t.tm_mon  = date.month_ - 1;
    t.tm_year = date.year_ - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
  
}

int ComputeDaysDiff(const Date& date_from, const Date& date_to) {
  const time_t timestamp_to = AsTimestamp(date_to);
  const time_t timestamp_from = AsTimestamp(date_from);
  static constexpr int SECONDS_IN_DAY = 60 * 60 * 24;
  return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

class Budget {
public:
    Budget() {
        int64_t n_days = ComputeDaysDiff(zero_date_, end_date_);
        money.resize(n_days, 0.0);
    }
    void WriteToBudget(Date& date_from, Date& date_to, int earned) {
        int index_from = CountIndex(date_from);
        int index_to = CountIndex(date_to);
        double earned_by_day = double(earned) / (index_to - index_from + 1);
        for (int i=index_from; i <= index_to; ++i) {
            money[i] += earned_by_day;
        }
    }

    double ComputeIncome(Date& date_from, Date& date_to) {
        int index_from = CountIndex(date_from);
        int index_to = CountIndex(date_to);
        return accumulate(money.begin() + index_from, money.begin() + index_to + 1, 0.0);
    }
private:
    int CountIndex(Date& date) {
        int index = ComputeDaysDiff(zero_date_, date);
        return index;
    }

    Date zero_date_ = {2000, 1, 1};
    Date end_date_ = {2100, 12, 31};
    vector<double> money;
    
};

void ParseDateStr(string& date_str, Date& date) {
    
    stringstream input(date_str);
    input >> date.year_;
    input.ignore(1);
    input >> date.month_;
    input.ignore(1);
    input >> date.day_;
}


int main() {
    cout.precision(25);
    int q;
    cin >> q;
    Budget budget;
    for (int i=0; i<q; ++i) {
    
        string op, date_from_str, date_to_str;
        cin >> op >> date_from_str >> date_to_str;
        int s;
        if (op == "Earn") {
            cin >> s;
        }
        Date date_from, date_to;
        ParseDateStr(date_from_str, date_from);
        ParseDateStr(date_to_str, date_to);
        if (op == "Earn") {
            budget.WriteToBudget(date_from, date_to, s);
        } else {
            cout << budget.ComputeIncome(date_from, date_to) << endl;
        }

    }
    
    return 0;
}

