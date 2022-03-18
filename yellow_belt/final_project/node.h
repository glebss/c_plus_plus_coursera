#pragma once
#include <memory>
#include "date.h"
using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
    Or
};

struct Node {
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

struct EmptyNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override;
};

struct DateComparisonNode : public Node {
    DateComparisonNode(const Comparison& cmp, const Date& date);
    bool Evaluate(const Date& date, const string& event) const override;
    const Comparison cmp_;
    const Date date_;
};

struct EventComparisonNode : public Node {
    EventComparisonNode(const Comparison& cmp, const string& event);
    bool Evaluate(const Date& date, const string& event) const override;
    const Comparison cmp_;
    const string event_;
};


struct LogicalOperationNode : public Node {
    LogicalOperationNode(const LogicalOperation& logical_op,
                         const shared_ptr<Node>& left, 
                         const shared_ptr<Node> right);
    bool Evaluate(const Date& date, const string& event) const override;
    const LogicalOperation op_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};

void TestLogicalNode();
void TestEventNode();
void TestDateNode();