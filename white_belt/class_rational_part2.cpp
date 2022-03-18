#include <iostream>
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



int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}