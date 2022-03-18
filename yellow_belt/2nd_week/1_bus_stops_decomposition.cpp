#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator>>(istream& is, Query& q) {
  string QueryStr;
  string stop;
  vector<string> stops;
  is >> QueryStr;
  if (QueryStr == "NEW_BUS") {
      q.type = QueryType::NewBus;
      is >> q.bus;
      int stop_count;
      is >> stop_count;
      for (int i=0; i<stop_count; ++i) {
          string cur_stop;
          is >> cur_stop;
          stops.push_back(cur_stop);
      }
      q.stops = stops;
  } else if (QueryStr == "BUSES_FOR_STOP") {
      q.type = QueryType::BusesForStop;
      is >> q.stop;
  } else if (QueryStr == "STOPS_FOR_BUS") {
      q.type = QueryType::StopsForBus;
      is >> q.bus;
  } else {
      q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
  string info;
  string stop;
  vector<string> buses;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
  if (r.buses.size() == 0) {
      os << r.info;
      return os;
  }
  for (const auto& b : r.buses) {
      os << b << " ";
  }
  return os;
}

struct StopsForBusResponse {
  string info;
  string bus;
  vector<string> stops;
  map<string, vector<string>> stop_to_buses;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
  if (r.stops.size() == 0) {
      os << r.info;
      return os;
  }
  for (const auto& s : r.stops) {
      os << "Stop " << s << ": ";
      vector<string> buses = r.stop_to_buses.at(s);
      if (buses.size() == 1 && buses[0] == r.bus) {
          os << "no interchange";
      } else {
          for (const auto& b : buses) {
              if (b != r.bus) {
                  os << b << " ";
              }
          }
      }
      os << endl;
  }
  return os;
}

struct AllBusesResponse {
  string info;
  map<string, vector<string>> bus_to_stops;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
  if (r.bus_to_stops.size() == 0) {
      os << r.info;
      return os;
  }
  for (const auto& item : r.bus_to_stops) {
      os << "Bus " << item.first << ": ";
      for (const auto& s : item.second) {
          os << s << " ";
      }
      os << endl;
  }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      bus_to_stops[bus] = stops;
      for (const auto& s : stops) {
          stop_to_buses[s].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      BusesForStopResponse response;
      if (stop_to_buses.count(stop) == 0) {
          response.info = "No stop";
          return response;
      }
      response.buses = stop_to_buses.at(stop);
      response.stop = stop;
      return response;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
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

  AllBusesResponse GetAllBuses() const {
      AllBusesResponse response;
      if (bus_to_stops.size() == 0) {
          response.info = "No buses";
          return response;
      }
      response.bus_to_stops = bus_to_stops;
      return response;
  }
private:
    map<string, vector<string>> bus_to_stops;
    map<string, vector<string>> stop_to_buses; 
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}