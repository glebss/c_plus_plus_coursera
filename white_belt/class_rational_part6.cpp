#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>
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
        if (denominator == 0) {
            throw invalid_argument("");
        }
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
    if (rhs.Numerator() == 0) {
        throw domain_error("");
    }
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}