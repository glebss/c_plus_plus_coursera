#include "database.h"
#include <utility>
#include <algorithm>


void Database::Add(const Date& date, const string& event) {
    
    if (events_pair.count(date) == 0) {
        set<string> s;
        vector<string> v;
        events_pair[date] = make_pair(s, v);
        events_pair[date].first.insert(event);
        events_pair[date].second.push_back(event);
    } else if (events_pair[date].first.count(event) == 0) {
        events_pair[date].first.insert(event);
        events_pair[date].second.push_back(event);
    }
}

void Database::Print(ostream& output) const {
    for (const auto& key : events_pair) {
        for (const auto& value : events_pair.at(key.first).second) {
            output << key.first << " " << value << endl;
        }
    }
}

int Database::RemoveIf(function<bool(const Date&, const string&)> predicate) {
    int res = 0;
    Date date;
    vector<Date> dates_to_del;
    for (auto& item : events_pair) {
        date = item.first;
        set<string> new_events;
        vector<string> vector_events = events_pair.at(date).second;
        for (auto it=events_pair.at(date).first.begin(); it != events_pair.at(date).first.end(); ++it) {
            if (predicate(date, *it)) {
                res += 1;
            } else {
                new_events.insert(*it);
            }
        }
        if (new_events.empty()) {
            dates_to_del.push_back(date);
            continue;
        }
        
        auto it = remove_if(vector_events.begin(), vector_events.end(), 
                            [date, predicate](const string& event){ return predicate(date, event); });
        vector_events.erase(it, vector_events.end());
        events_pair[date] = make_pair(new_events, vector_events);
    }
    for (const auto& date : dates_to_del) {
        events_pair.erase(date);
    }
    return res;
}

vector<pair<Date, string>> Database::FindIf(function<bool(const Date&, const string&)> predicate) const {
    vector<pair<Date, string>> res;
    Date date;
    for (const auto& item : events_pair) {
        date = item.first;
        for (const auto& event : events_pair.at(date).second) {
            if (predicate(date, event)) {
                res.push_back(make_pair(date, event));
            }
        }
    }
    return res;
}

string Database::Last(const Date& date) const {
    if (events_pair.empty()) { return "No entries"; }
    auto upper = events_pair.upper_bound(date);
    if (upper == events_pair.begin()) { 
        return "No entries";
    } else {
        ostringstream out;
        --upper;
        out << upper->first << " " << upper->second.second.back();
        return out.str();
    }
}
