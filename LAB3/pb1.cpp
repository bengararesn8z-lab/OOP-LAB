#include <bits/stdc++.h>
using namespace std;
class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double area() const {
        return width * height;
    }
    double perimeter() const {
        return 2 * (width + height);
    }
    void comparePerimeter(const Rectangle& other) const {
        double p1 = this->perimeter();
        double p2 = other.perimeter();
        if (p1 > p2)
            cout << "Perimetrul primului dreptunghi este mai mare.\n";
        else if (p1 < p2)
            cout << "Perimetrul celui de-al doilea dreptunghi este mai mare.\n";
        else
            cout << "Perimetrele sunt egale.\n";
    }
    void compareArea(const Rectangle& other) const {
        double a1 = this->area();
        double a2 = other.area();
        if (a1 > a2)
            cout << "Aria primului dreptunghi este mai mare.\n";
        else if (a1 < a2)
            cout << "Aria celui de-al doilea dreptunghi este mai mare.\n";
        else
            cout << "Ariile sunt egale.\n";
    }
};
int main() {
    Rectangle r1(4, 6);
    Rectangle r2(5, 5);
    cout << "Dreptunghi 1: perimetru = " << r1.perimeter()
         << ", aria = " << r1.area() << endl;
    cout << "Dreptunghi 2: perimetru = " << r2.perimeter()
         << ", aria = " << r2.area() << endl;
    cout << "\nComparatii\n";
    r1.comparePerimeter(r2);
    r1.compareArea(r2);
    return 0;
}
