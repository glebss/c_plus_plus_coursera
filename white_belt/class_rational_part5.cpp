#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a+b;
}



class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1; 
    }

    Rational(int numerator, int denominator) {
        int GCD = gcd(abs(numerator), abs(denominator));
        numerator_ = numerator / GCD;
        denominator_ = denominator / GCD;
        if (numerator_ == 0) {
            denominator_ = 1;
        } else if (denominator_ < 0) {
            numerator_ *= -1;
            denominator_ *= -1;
        }
    }

    int Numerator() const {
        return numerator_;
    }

    int Denominator() const {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(), 
                    lhs.Denominator()*rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(), 
                    lhs.Denominator()*rhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}


ostream& operator<<(ostream& out, const Rational& rational) {
    out << rational.Numerator() << "/" << rational.Denominator();
    return out;
}

istream& operator>>(istream& in, Rational& rational) {
    int numerator;
    int denumerator;
    char sep;
    in >> numerator;
    in >> sep;
    if (sep != '/') {
        return in;
    }

    in >> denumerator;
    if (!in) {
        return in;
    }
    rational = {numerator, denumerator};
    return in;

}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}