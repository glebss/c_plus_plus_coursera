#include "bus_manager.h"
using namespace std;


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    bus_to_stops[bus] = stops;
    for (const auto& s : stops) {
        stop_to_buses[s].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse response;
    if (stop_to_buses.count(stop) == 0) {
        response.info = "No stop";
        return response;
    }
    response.buses = stop_to_buses.at(stop);
    response.stop = stop;
    return response;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse response;
    if (bus_to_stops.count(bus) == 0) {
        response.info = "No bus";
        return response;
    }
    response.bus = bus;
    response.stops = bus_to_stops.at(bus);
    response.stop_to_buses = stop_to_buses;
    return response;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse response;
    if (bus_to_stops.size() == 0) {
        response.info = "No buses";
        return response;
    }
    response.bus_to_stops = bus_to_stops;
    return response;
}
