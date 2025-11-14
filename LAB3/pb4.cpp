#include <bits/stdc++.h>
using namespace std;
class Results {
private:
    double x1;
    double x2;
    bool equalRoots;
public:
    Results(double x1, double x2, bool equalRoots = false) {
        this->x1 = x1;
        this->x2 = x2;
        this->equalRoots = equalRoots;
    }
    double getX1() const { return x1; }
    double getX2() const { return x2; }
    bool areEqual() const { return equalRoots; }
    void display() const {
        if (equalRoots) {
            cout << "Ecuatia are o singura solutie reala (dubla): x = " << x1 << "\n";
        } else {
            cout << "Ecuatia are doua solutii reale: x1 = " << x1 << ", x2 = " << x2 << "\n";
        }
    }
};
class Equation2 {
private:
    double a, b, c;
public:
    Equation2(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    optional<Results> solve() const {
        if (a == 0) {
            if (b == 0) {
                return nullopt;
            } else {
                double x = -c / b;
                return Results(x, x, true);
            }
        }
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            return nullopt;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            return Results(x, x, true);
        } else {
            double sqrtDelta = sqrt(delta);
            double x1 = (-b + sqrtDelta) / (2 * a);
            double x2 = (-b - sqrtDelta) / (2 * a);
            return Results(x1, x2, false);
        }
    }
};
int main() {
    double a, b, c;
    cout << "Rezolvam ecuatia de forma: ax^2 + bx + c = 0\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    Equation2 eq(a, b, c);
    optional<Results> res = eq.solve();
    if (!res.has_value()) {
        cout << "Ecuatia nu are solutii reale sau nu este o ecuatie valida de gradul 2.\n";
    } else {
        res->display();
    }
    return 0;
}
