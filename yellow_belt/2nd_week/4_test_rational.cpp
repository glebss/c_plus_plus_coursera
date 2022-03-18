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

// int gcd(int a, int b) {
//     while (a > 0 && b > 0) {
//         if (a > b) {
//             a = a % b;
//         } else {
//             b = b % a;
//         }
//     }
//     return a+b;
// }

// class Rational {
// public:
//     Rational() {
//         numerator_ = 0;
//         denominator_ = 1; 
//     }

//     Rational(int numerator, int denominator) {
//         int GCD = gcd(abs(numerator), abs(denominator));
//         numerator_ = numerator / GCD;
//         denominator_ = denominator / GCD;
//         if (numerator_ == 0) {
//             denominator_ = 1;
//         } else if (denominator_ < 0) {
//             numerator_ *= -1;
//             denominator_ *= -1;
//         }
//     }

//     int Numerator() const {
//         return numerator_;
//     }

//     int Denominator() const {
//         return denominator_;
//     }

// private:
//     int numerator_;
//     int denominator_;
// };

void TestRational() {
    
    {
        Rational r;
        AssertEqual(r.Numerator(), 0, "Default constructor, numerator = 0");
        AssertEqual(r.Denominator(), 1, "Default constructor, denominator = 1");
    }

    {
        Rational r(2, 3);
        AssertEqual(r.Numerator(), 2, "Numerator 2");
        AssertEqual(r.Denominator(), 3, "Denominator 3");
    }

    {
        Rational r(5, 10);
        AssertEqual(r.Numerator(), 1, "Numerator from 5 to 1");
        AssertEqual(r.Denominator(), 2, "Denominator from 10 to 2");
    }

    {
        Rational r(1, -2);
        AssertEqual(r.Numerator(), -1, "Numerator from 1 to -1");
        AssertEqual(r.Denominator(), 2, "Denominator from -2 to 2");
    }

    {
        Rational r(-1, 2);
        AssertEqual(r.Numerator(), -1, "Numerator -1");
        AssertEqual(r.Denominator(), 2, "Denominator 2");
    }

    {
        Rational r(-1, -2);
        AssertEqual(r.Numerator(), 1, "Numerator 1");
        AssertEqual(r.Denominator(), 2, "Denominator 2");
    }

    {
        Rational r(0, 5);
        AssertEqual(r.Numerator(), 0, "Numerator 0");
        AssertEqual(r.Denominator(), 1, "Denominator from 5 to 1");
    }
}

int main() {
  TestRunner runner;
  runner.RunTest(TestRational, "TestRational");
  return 0;
}