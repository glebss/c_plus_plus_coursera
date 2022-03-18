#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }   
    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else if (operation == '-') {
            operation = '+';
        } else if (operation == '*') {
            operation = '/';
        } else {
            operation = '*';
        }
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else if (operation == '-') {
            return source_value - value;
        } else if (operation == '*') {
            return source_value * value;
        } else {
            return source_value / value;
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(const char& operation, const float& value) {
        parts.push_back({operation, value});
    };
    double Apply(double value) const {
        for (const auto& p : parts) {
            value = p.Apply(value);
        }
        return value;
    };
    void Invert() {
        for (auto& p: parts) {
            p.Invert();
        }
        reverse(parts.begin(), parts.end());
    };
private:
    vector<FunctionPart> parts;
};


// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('-', image.freshness * params.a + params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   cout << ComputeImageWeight(params, image) << endl;
//   cout << ComputeQualityByWeight(params, image, 46) << endl;
//   return 0;
// }
