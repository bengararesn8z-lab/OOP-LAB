#include <bits/stdc++.h>
using namespace std;
float toFloat(const string& s) {
    try {
        size_t idx;
        float val = stof(s, &idx);
        if (idx != s.size()) {
            throw invalid_argument("String contine caractere invalide.");
        }
        return val;
    } catch (...) {
        throw invalid_argument("Input invalid: " + s);
    }
}
float rectangleArea(float a, float b) {
    if (a <= 0 || b <= 0)
        throw invalid_argument("Laturile trebuie sa fie pozitive.");
    return a * b;
}
float squareArea(float a, float = 0) {
    if (a <= 0)
        throw invalid_argument("Latura trebuie sa fie pozitiva.");
    return a * a;
}
float computeArea(const string& s1,
                  const string& s2 = "",
                  float (*func)(float, float) = squareArea)
{
    float a = toFloat(s1);
    float b = 0;
    if (s2 != "")
        b = toFloat(s2);
    else
        b = a;
    return func(a, b);
}
int main() {
    try {
        cout << "Arie patrat: "
             << computeArea("5") << endl;
        cout << "Arie dreptunghi: "
             << computeArea("4", "6", rectangleArea) << endl;
        cout << "Test invalid: "
             << computeArea("192a") << endl;
    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    return 0;
}
