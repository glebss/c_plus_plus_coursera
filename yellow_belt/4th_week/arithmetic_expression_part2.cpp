#include <iostream>
#include <deque>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string,int> priorities = {{"-", 0}, {"+", 0}, {"*", 1}, {"/", 1}};
    int x, n;
    cin >> x >> n;
    int prev_priority = 1;
    int priority;
    deque<string> res;
    res.push_back(to_string(x));
    for (int i=0; i < n; ++i) {
        string op;
        int num;
        cin >> op >> num;
        priority = priorities.at(op);
        if (priority > prev_priority) {
            res.push_front("(");
            res.push_back(")");
        }
        res.push_back(" " + op + " ");
        res.push_back(to_string(num));
        prev_priority = priority;
    }
    string res_str;
    for (const auto el : res) {
        cout << el;
    }
    cout << endl;

    return 0;
}