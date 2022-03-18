#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    int num_month = 0;

    std::map<int, int> days_in_months = {{0, 31}, {1, 28}, {2, 31}, 
                                        {3, 30}, {4, 31}, {5, 30},
                                        {6, 31}, {7, 31}, {8, 30},
                                        {9, 31}, {10, 30}, {11, 31}};
    
    std::vector<std::vector<std::string>> current_duties(days_in_months[num_month]);
    
    int q;
    std::cin >> q;
    for (int i=0; i < q; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "ADD") {
            int n_day;
            std::string s;
            std::cin >> n_day >> s;
            current_duties[n_day-1].push_back(s);
        } else if (op == "DUMP") {
            int n_day;
            std::cin >> n_day;
            std::cout << current_duties[n_day-1].size() << " ";
            for (auto& el : current_duties[n_day-1]) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        } else {
            int prev_num_month = num_month;
            num_month++;

            if (num_month > 11) {
                num_month %= 12;
            }

            if (days_in_months[prev_num_month] <= days_in_months[num_month]) {
                current_duties.resize(days_in_months[num_month], {});
            } else {
                std::vector<std::string> additional_duties;
                int days_diff = days_in_months[prev_num_month] - days_in_months[num_month];
                for (int k=0; k<days_diff; ++k) {
                    std::vector<std::string> day_duties = current_duties[days_in_months[num_month]+k];
                    additional_duties.insert(end(additional_duties), begin(day_duties), end(day_duties));
                }
                current_duties.resize(days_in_months[num_month]);
                current_duties[days_in_months[num_month]-1].insert(end(current_duties[days_in_months[num_month]-1]), 
                                                        begin(additional_duties), end(additional_duties));
            }
            

        }
    }
    return 0;
}
