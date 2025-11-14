#include <iostream>
#include <iomanip>
class TemperatureConverter {
public:
    static double celsius_to_fahrenheit(double celsius) {
        return (celsius * (9.0 / 5.0)) + 32.0;
    }
    static double fahrenheit_to_celsius(double fahrenheit) {    
        return (fahrenheit - 32.0) * (5.0 / 9.0);
    }
};
int main() {
    std::cout << std::fixed << std::setprecision(2);
    double temp_c = 100.0;  
    double temp_f = TemperatureConverter::celsius_to_fahrenheit(temp_c);
    std::cout << temp_c << "C este egal cu " << temp_f << "F" << std::endl;    
    double temp_f_2 = 212.0;
    double temp_c_2 = TemperatureConverter::fahrenheit_to_celsius(temp_f_2);
    std::cout << temp_f_2 << "F este egal cu " << temp_c_2 << "C" << std::endl;
    double temp_c_3 = 0.0;
    double temp_f_3 = TemperatureConverter::celsius_to_fahrenheit(temp_c_3);
    std::cout << temp_c_3 << "C este egal cu " << temp_f_3 << "F" << std::endl;
    return 0;
}
