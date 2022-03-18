#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include "date.h"
#include "node.h"
using namespace std;


struct Entry {

};

class Database {
public:
    Database() {};
    void Add(const Date& date, const string& event);
    void Print(ostream& output) const;
    int RemoveIf(function<bool(const Date&, const string&)> predicate);
    vector<pair<Date, string>> FindIf(function<bool(const Date&, const string&)> predicate) const;
    string Last(const Date& date) const;
private:
    map<Date, pair<set<string>, vector<string>>> events_pair;
};

void TestDbAdd();
void TestDbFind();
void TestDbLast();
void TestDbRemoveIf();
void TestInsertionOrder();
void TestDatabase();