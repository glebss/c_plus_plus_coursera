#include "query.h"
using namespace std;

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

// int main() {
//     Query q;
//     cin >> q;
//     return 0;
// }