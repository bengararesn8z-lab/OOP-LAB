#include <bits/stdc++.h>
using namespace std;
// clasa care modeleaza ecuatia ax + b = 0
class LinearEquation {
private:
    double a, b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}
       double solve() const {
        if (a == 0 && b == 0)
            throw runtime_error("Ecuatia are un numar infinit de solutii.");
        else if (a == 0)
            throw runtime_error("Ecuatia nu are solutii (a = 0, b ≠ 0).");
        return -b / a;
    }
      void display() const {
        cout << a << "x + " << b << " = 0" << endl;
    }
};
int main() {
    try {
        double a, b;
        cout << "Introduceti coeficientii a si b: ";
        cin >> a >> b;
        LinearEquation eq(a, b);
        eq.display();
        double x = eq.solve();
        cout << "Solutia este: x = " << x << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Eroare: " << e.what() << endl;
    }
    return 0;
}
