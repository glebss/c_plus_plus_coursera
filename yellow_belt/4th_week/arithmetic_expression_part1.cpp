#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    deque<string> res;
    res.push_back(to_string(x));
    for (int i=0; i < n; ++i) {
        string op;
        int num;
        cin >> op >> num;
        res.push_front("(");
        res.push_back(")");
        res.push_back(" " + op + " ");
        res.push_back(to_string(num));
    }
    string res_str;
    for (const auto el : res) {
        cout << el;
    }
    cout << endl;

    return 0;
}