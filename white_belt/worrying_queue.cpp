#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<bool> queue;
    int q;
    std::cin >> q;
    for (int i=0; i < q; ++i) {
        std::string op;
        int num;
        std::cin >> op;
        
        if (op == "COME") {
            std::cin >> num;
            queue.resize(queue.size()+num, false);
                
        } else if (op == "QUIET") {
            std::cin >> num;
            queue[num] = false;
        } else if (op == "WORRY") {
            std::cin >> num;
            queue[num] = true;
        } else {
            std::cout << std::count(queue.begin(), queue.end(), true) << std::endl;
        }
    }
    return 0;
}
