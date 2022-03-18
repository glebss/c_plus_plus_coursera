#include "phone_number.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream input(international_number);
    if (input.eof()) {
        throw invalid_argument(" ");
    }
    
    if (input.peek() != '+') {
        throw invalid_argument("");
    }
    input.ignore(1);
    if (!isdigit(input.peek())) {
        throw invalid_argument("");
    }
    getline(input, country_code_, '-');
    if (input.eof() || !isdigit(input.peek())) {
        throw invalid_argument("");
    }
    getline(input, city_code_, '-');
    if (input.eof()) {
        throw invalid_argument("");
    }
    getline(input, local_number_);
}

string PhoneNumber::GetCountryCode() const { return country_code_; }
string PhoneNumber::GetCityCode() const { return city_code_; }
string PhoneNumber::GetLocalNumber() const { return local_number_; }
string PhoneNumber::GetInternationalNumber() const { 
      return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}


// int main() {
//     const string phone_number = "+7-495-111-22-33";
//     PhoneNumber("+1-2-coursera-cpp");
//     // PhoneNumber("+7-495-1112233");
//     // +323-22-460002
//     //  * +1-2-coursera-cpp
//     //  * 1-2-333 - некорректный номер - не начинается на '+'
//     //  * +7-1233 - некорректный номер - есть только код страны и города
//     return 0;
// }