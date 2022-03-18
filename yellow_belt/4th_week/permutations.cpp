#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename It >
void PrintVec(It begin, It end) {
    for (auto it=begin; it != end; ++it) {
        cout << *it << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i=1; i <= n; ++i) {
        nums.push_back(i);
    }
    sort(nums.rbegin(), nums.rend());
    PrintVec(nums.begin(), nums.end());
    cout << endl;
    while(prev_permutation(nums.begin(), nums.end())) {
        PrintVec(nums.begin(), nums.end());
        cout << endl;
    }
    return 0;
}


