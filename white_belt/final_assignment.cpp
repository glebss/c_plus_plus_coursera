#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <exception>
using namespace std;

class Date {
public:
    Date() {}
    Date(int year, int month, int day) {
        day_ = day;
        month_ = month;
        year_ = year;
    }
  int GetYear() const {
      return year_;
  }
  int GetMonth() const {
      return month_;
  }
  int GetDay() const {
      return day_;
  }
private:
    int year_;
    int month_;
    int day_;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        } else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    } else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

ostream& operator<<(ostream& out, const Date& date) {
    out << setfill('0');
    out << setw(4) << date.GetYear() << "-" 
        << setw(2) << date.GetMonth() << "-" 
        << setw(2) << date.GetDay();
    return out;
}

Date ParseDate(const string& string_date) {
    
    stringstream input(string_date);
    int year, month, day;
    if (input.eof()) {
        throw runtime_error("Wrong date format: " + string_date);
    }

    if (input.peek() == '-') {
        input.ignore(1);
        if (!isdigit(input.peek())) { throw runtime_error("Wrong date format: " + string_date); }
        input >> year;
        year *= -1;
    } else if (input.peek() == '+') {
        input.ignore(1);
        if (!isdigit(input.peek())) { throw runtime_error("Wrong date format: " + string_date); }
        input >> year;
    } else if (!isdigit(input.peek())) {
        throw runtime_error("Wrong date format: " + string_date);
    } else if (isdigit(input.peek())) {
        input >> year;
    } else {
        throw runtime_error("Wrong date format: " + string_date);
    }
    if (input.peek() != '-') {
        throw runtime_error("Wrong date format: " + string_date);
    }
    input.ignore(1);
    if (input.peek() == '-') {
        input.ignore(1);
        if (!isdigit(input.peek())) { throw runtime_error("Wrong date format: " + string_date); }
        input >> month;
        month *= -1;
    } else if (input.peek() == '+') {
        input.ignore(1);
        if (!isdigit(input.peek())) { throw runtime_error("Wrong date format: " + string_date); }
        input >> month;
    } else if (!isdigit(input.peek())) {
        throw runtime_error("Wrong date format: " + string_date);
    } else if (isdigit(input.peek())) {
        input >> month;
    } else {
        throw runtime_error("Wrong date format: " + string_date);
    }

    if (input.peek() != '-') {
        throw runtime_error("Wrong date format: " + string_date);
    }
    input.ignore(1);
    if (input.peek() == '-') {
        input.ignore(1);
        if (!isdigit(input.peek())) { throw runtime_error("Wrong date format: " + string_date); }
        input >> day;
        month *= -1;
    } else if (input.peek() == '+') {
        input.ignore(1);
        if (!isdigit(input.peek())) { throw runtime_error("Wrong date format: " + string_date); }
        input >> day;
    } else if (!isdigit(input.peek())) {
        throw runtime_error("Wrong date format: " + string_date);
    } else if (isdigit(input.peek())) {
        input >> day;
    } else {
        throw runtime_error("Wrong date format: " + string_date);
    }

    if (!input.eof()) { throw runtime_error("Wrong date format: " + string_date); }
    if (month < 1 || month > 12) {
        throw runtime_error("Month value is invalid: " + to_string(month));
    }
    if (day < 1 || day > 31) {
        throw runtime_error("Day value is invalid: " + to_string(day));
    }

    return Date(year, month, day);
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      if (!event.empty()) {
          events[date].insert(event);
      }
  };
  
  bool DeleteEvent(const Date& date, const string& event) {
      if (events.count(date) > 0 && events.at(date).count(event) > 0) {
          events.at(date).erase(event);
          return true;
      } else {
          return false;
      }
  }
  int DeleteDate(const Date& date) {
      if (events.count(date) == 0) {
          return 0;
      }
      int n = events.at(date).size();
      events.erase(date);
      return n;
  }

  set<string> Find(const Date& date) const {
      set<string> res;
      if (events.count(date) > 0) {
          res = events.at(date);      
      }
      return res;
  }
  
  void Print() const {
    for (auto& p : events) {
        for (auto& s : p.second) {
            cout << p.first << ' ' << s << endl;
        }
    }
  }
private:
    map<Date, set<string>> events;
};

int main() {
  Database db;
    
  string command;
  try {
    while (getline(cin, command)) {
        
        string operation;
        stringstream input(command);
        input >> operation;
        if (operation == "Add") {
            string string_date;
            input >> string_date;
            string event;
            Date date = ParseDate(string_date);
            input >> event;
            db.AddEvent(date, event);
        } else if (operation == "Del") {
            string string_date, event;
            input >> string_date;
            Date date = ParseDate(string_date);
            if (!input.eof()) {
                input >> event;
            }
            if (!event.empty()) {
                if (db.DeleteEvent(date, event)) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            } else {
                int n = db.DeleteDate(date);
                cout << "Deleted " << n << " events" << endl;
            }
        
        } else if (operation == "Find") {
            string string_date;
            input >> string_date;
            Date date = ParseDate(string_date);
            set<string> res = db.Find(date);
            for (const auto& r : res) {
                cout << r << endl;
            }
            
        } else if (operation == "Print") {
            db.Print();
        } else if (operation.empty()) {
            continue;
        } else {
            throw runtime_error("Unknown command: " + command);
        }
    }
  } catch (exception& ex) {
      cout << ex.what() << endl;
  }

  return 0;
}