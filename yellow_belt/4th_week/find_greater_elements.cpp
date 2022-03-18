#include <set>
#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    // auto pos = find_if(elements.begin(), elements.end(), 
    //                     [&](T& el) { el > border; });
    vector<T> res;
    for (auto it=elements.begin(); it != elements.end(); ) {
        if (*it > border) {
            res.push_back(*it);
        }
        ++it;
    }
    // while (pos != elements.end()) {
    //     res.push_back(*pos);
    //     ++pos;
    // }
    
    return res;
}

// int main() {
//   for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
//     cout << x << " ";
//   }
//   cout << endl;
  
//   string to_find = "Python";
//   cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
//   return 0;
// }