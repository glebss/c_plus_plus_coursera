#include <string>
#include <algorithm>
#include <iostream>

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const std::string& s) {
        string_ = s;
    }
    std::string ToString() const {
        return string_;
    }
    void Reverse() {
        int n = string_.size();
        for (int i = 0; i < n / 2; ++i) {
            char tmp = string_[i];
            string_[i] = string_[n - i - 1];
            string_[n - i - 1] = tmp;
        }
    }
private:
    std::string string_;
};

// int main() {
//     using namespace std;
//   ReversibleString s("live");
//   s.Reverse();
//   cout << s.ToString() << endl;
  
//   s.Reverse();
//   const ReversibleString& s_ref = s;
//   string tmp = s_ref.ToString();
//   cout << tmp << endl;
  
//   ReversibleString empty;
//   cout << '"' << empty.ToString() << '"' << endl;
  
//   return 0;
// }