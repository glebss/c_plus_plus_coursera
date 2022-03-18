#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) 
    : cmp_(cmp), date_(date) 
{}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp_ == Comparison::Less) {
        return date < date_;
    } else if(cmp_ == Comparison::LessOrEqual) {
        return date < date_ || date_ == date;
    } else if (cmp_ == Comparison::Greater) {
        return date_ < date;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return date_ < date || date == date_;
    } else if (cmp_ == Comparison::Equal) {
        return date_ == date;
    } else if (cmp_ == Comparison::NotEqual) {
        return !(date_ == date);
    } else {
        throw runtime_error("Not known comparison operation you bastard!");
    }
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event)
    : cmp_(cmp), event_(event)
{}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp_ == Comparison::Equal) {
        return event_ == event;
    } else if(cmp_ == Comparison::NotEqual) {
        return event_ != event;
    } else if (cmp_ == Comparison::Greater) {
        return event_ < event; 
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return event_ < event || event_ == event;
    } else if (cmp_ == Comparison::Less) {
        return event < event_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return event < event_ || event == event_;
    } else {
        throw runtime_error("Only (not)equal operations can be to string events you bastard!");
    }
}
    
LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logical_op, 
                                           const shared_ptr<Node>& left, 
                                           const shared_ptr<Node> right) 
    : op_(logical_op), left_(left), right_(right)  
{}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    bool left_ret = left_->Evaluate(date, event);
    bool right_ret = right_->Evaluate(date, event);
    if (op_ == LogicalOperation::Or) {
        return left_ret || right_ret;
    } else if (op_ == LogicalOperation::And) {
        return left_ret && right_ret;;
    } else {
        throw runtime_error("Logical operation not known you bastard!");
    }
}