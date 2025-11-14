#include <bits/stdc++.h>
class Calculator {
public:
    static int operate(int a, int b, int (*func)(int, int)) {
        try {
            return func(a, b);
        } catch (const std::exception& e) {
            std::cerr << "Eroare la operate(int): " << e.what() << "\n";
            return 0;
        }
    }
    static double operate(double a, double b, double (*func)(double, double)) {
        try {
            return func(a, b);
        } catch (const std::exception& e) {
            std::cerr << "Eroare la operate(double): " << e.what() << "\n";
            return 0.0;
        }
    }
};
int divideInt(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Impartire la zero (int).");
    return a / b;
}
double divideDouble(double a, double b) {
    if (b == 0.0)
        throw std::runtime_error("Impartire la zero (double).");
    return a / b;
}
int main() {
    int x = 10, y = 0;
    double p = 5.5, q = 0.0;
    std::cout << "Operatie int: "
              << Calculator::operate(x, y, divideInt) << "\n";
    std::cout << "Operatie double: "
              << Calculator::operate(p, q, divideDouble) << "\n";
    return 0;
}
