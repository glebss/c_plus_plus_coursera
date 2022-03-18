#include <iostream>
#include <sstream>
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
int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input1("1/22/3"), input2("1/2");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
    }

    cout << "OK" << endl;
    return 0;
}