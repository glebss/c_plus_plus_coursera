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

bool IsPalindrom(std::string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

void TestIsPalindrom() {
    Assert(IsPalindrom(""), "Empty string");
    Assert(IsPalindrom(" "), "One space");
    Assert(IsPalindrom("  "), "Two spaces");
    Assert(IsPalindrom("abba"), "Even characters");
    Assert(IsPalindrom("abcba"), "Odd characters");
    Assert(IsPalindrom("aa aa"), "With space in the middle");
    Assert(!IsPalindrom("ab"), "Not palindrom");
    Assert(!IsPalindrom("aaAA"), "Case sensetive palindrom");
    Assert(!IsPalindrom("!@#$%^&*()"), "Line of symbols");
    Assert(!IsPalindrom("Amama"), "Amama test");
    Assert(!IsPalindrom("bbb ccc www"), "Line of Palindroms");
    Assert(!IsPalindrom(" aaa"), "Space in the beginning");
    Assert(!IsPalindrom("aaa "), "Space in the end");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestIsPalindrom, "TestIsPalindrom");
  return 0;
}