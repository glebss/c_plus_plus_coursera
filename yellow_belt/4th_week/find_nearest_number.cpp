#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
    if (numbers.size() == 0) {
        return numbers.end();
    }

    const auto lower = numbers.lower_bound(border);
    if (*lower == border) { return lower; }
    
    if (lower == numbers.end()) {
        return prev(numbers.end());
    }
    if (lower == numbers.begin()) {
        return lower;
    }

    
    int lower_abs = abs(border - *prev(lower));
    int upper_abs = abs(border - *lower);
    if (lower_abs <= upper_abs) {
        return prev(lower);
    }
    return lower;
}

// int main() {
//   set<int> numbers = {1, 4, 6};
//   cout <<
//       *FindNearestElement(numbers, 0) << " " <<
//       *FindNearestElement(numbers, 3) << " " <<
//       *FindNearestElement(numbers, 5) << " " <<
//       *FindNearestElement(numbers, 6) << " " <<
//       *FindNearestElement(numbers, 100) << endl;
      
//   set<int> empty_set;
  
//   cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
//   return 0;
// }
