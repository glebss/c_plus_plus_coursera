#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
    return x+y;
}
string Reverse(string s) {
    size_t n = s.size();
    for (size_t i=0; i<s.size()/2; ++i) {
        char c = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = c;
    }
    return s;
}
void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}