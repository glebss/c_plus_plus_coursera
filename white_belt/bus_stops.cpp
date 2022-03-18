#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;
    std::map<std::string, std::vector<std::string>> bus_stops;
    std::map<std::string, std::vector<std::string>> buses_for_stop;
    for (int i = 0; i < q; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "NEW_BUS") {
            std::string bus;
            int stop_count;
            std::cin >> bus >> stop_count;
            for (int j=0; j < stop_count; ++j) {
                std::string stop;
                std::cin >> stop;
                bus_stops[bus].push_back(stop);
                if (std::find(buses_for_stop[stop].begin(), buses_for_stop[stop].end(), bus) == buses_for_stop[stop].end()) {
                    buses_for_stop[stop].push_back(bus);
                }
            }
        } else if (op == "BUSES_FOR_STOP") {
            std::string stop;
            std::cin >> stop;
            if (buses_for_stop.count(stop) > 0) {
                for (const auto& b : buses_for_stop[stop]) {
                    std::cout << b << " ";
                } 
                std::cout << std::endl;
            } else { std::cout << "No stop" << std::endl; }
        } else if (op == "STOPS_FOR_BUS") {
            std::string bus;
            std::cin >> bus;
            if (bus_stops.count(bus) > 0) {
                for (const auto& s: bus_stops[bus]) {
                    std::cout << "Stop " << s << ": ";
                    std::vector<std::string> buses_this_stop = buses_for_stop[s];
                    if (buses_this_stop.size() == 1 && buses_this_stop[0] == bus) {
                        std::cout << "no interchange" << std::endl;
                    } else {
                        for (const auto& b : buses_this_stop) {
                            if (b != bus) {
                                std::cout << b << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                }
            } else {
                std::cout << "No bus" << std::endl;
            }
        } else {
            if (bus_stops.size() == 0) {
                std::cout << "No buses" << std::endl;
            } else {
                for (const auto& item : bus_stops) {
                    std::string bus = item.first;
                    std::vector<std::string> stops = item.second;
                    std::cout << "Bus " << bus << ": ";
                    for (const auto& s : stops) {
                        std::cout << s << " ";
                    } 
                    std::cout << std::endl;

                }
            }
        }

    }
    return 0;
}