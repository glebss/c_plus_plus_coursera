#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

struct BusesForStopResponse {
  string info;
  string stop;
  vector<string> buses;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  string info;
  string bus;
  vector<string> stops;
  map<string, vector<string>> stop_to_buses;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  string info;
  map<string, vector<string>> bus_to_stops;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r);