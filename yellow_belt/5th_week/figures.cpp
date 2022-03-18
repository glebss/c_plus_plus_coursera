#include <memory>
#include <string>
#include <cmath>
#include <iostream>
#include <istream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class Figure {
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Triangle : public Figure {
public:
    Triangle(const int a, const int b, const int c) 
        : perimeter_(CalcPerimeter(a, b, c)),
          area_(CalcArea(a, b, c))
    {}

    double Perimeter() override {
        return perimeter_;
    }
    double Area() override {
        return area_;
    }
    string Name() override {
        return "TRIANGLE";
    }
private:
    double CalcArea(const int a, const int b, const int c) {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double CalcPerimeter(const int a, const int b, const int c) {
        return a + b + c;
    }
    const double perimeter_;
    const double area_;
};

class Rect : public Figure {
public:
    Rect(const int w, const int h)
        : width_(w), height_(h)
    {}
    double Perimeter() override {
        return 2*(width_ + height_);
    }
    double Area() override {
        return width_ * height_;
    }
    string Name() override {
        return "RECT";
    }
private:
    const int width_;
    const int height_;
};

class Circle : public Figure {
public:
    Circle(const int r)
        : r_(r)
    {}
    double Perimeter() override {
        return 2 * 3.14 * r_;
    }
    double Area() override {
        return 3.14 * r_ * r_;
    }
    string Name() override {
        return "CIRCLE";
    }
private:
    const int r_;
};

shared_ptr<Figure> CreateFigure(istream& input) {
    string fig;
    input >> fig;
    if (fig == "RECT") {
        int w, h;
        input >> w >> h;
        return make_shared<Rect>(w, h);
    } else if (fig == "TRIANGLE") {
        int a, b, c;
        input >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else {
        int r;
        input >> r;
        return make_shared<Circle>(r);
    }
}


// int main() {
//   vector<shared_ptr<Figure>> figures;
//   for (string line; getline(cin, line); ) {
//     istringstream is(line);

//     string command;
//     is >> command;
//     if (command == "ADD") {
//       // Пропускаем "лишние" ведущие пробелы.
//       // Подробнее об std::ws можно узнать здесь:
//       // https://en.cppreference.com/w/cpp/io/manip/ws
//       is >> ws;
//       figures.push_back(CreateFigure(is));
//     } else if (command == "PRINT") {
//       for (const auto& current_figure : figures) {
//         cout << fixed << setprecision(3)
//              << current_figure->Name() << " "
//              << current_figure->Perimeter() << " "
//              << current_figure->Area() << endl;
//       }
//     }
//   }
//   return 0;
// }