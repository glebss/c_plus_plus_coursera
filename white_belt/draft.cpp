#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string GetPositivity(int x) {
    return x > 0 ? "positive"
                 : (x == 0 ? "zero" : "negative");
}

string get_name(const string& s) {
    string res = s;
    return res + "aaaaa";
}

class A {
private:
    
};

int main() {
    
    string s = "bbbbb";
    string res = get_name(s);
    cout << res << endl;
    cout << s << endl;
    int n = 55;
    auto n_str = to_string(n);
    cout << n_str << endl;
    return 0;

}