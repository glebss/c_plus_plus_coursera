#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> res;
    auto pos = s.begin();
    auto pred_pos = s.begin();
    while (pos != s.end()) {
        pos = find(pos, s.end(), ' ');
        res.push_back(string(pred_pos, pos));
        if (pos == s.end()) {break;}
        ++pos;
        pred_pos = pos;
    }
    return res;
}

// int main() {
//   string s = "C Cpp Java Python";

//   vector<string> words = SplitIntoWords(s);
//   cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       cout << "/";
//     }
//     cout << *it;
//   }
//   cout << endl;
  
//   return 0;
// }