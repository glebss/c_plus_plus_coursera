#include "responses.h"
using namespace std;

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

// int main() {
//     Query q;
//     cin >> q;
//     return 0;
// }