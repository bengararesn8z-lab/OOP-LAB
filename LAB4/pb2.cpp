#include <bits/stdc++.h>
using namespace std;
class Address {
private:
    string street;
    int number;
public:
    Address(string street = "Unknown", int number = 0)
        : street(street), number(number) {}

    string getStreet() const { return street; }
    int getNumber()   const { return number; }

    void display() const {
        cout << street << " nr. " << number;
    }
};
class Person {
protected:
    string name;
    int age;
    Address address;
public:
    Person(string name, int age, Address address)
        : name(name), age(age), address(address) {}
    virtual void display() const {
        cout << name << " (" << age << ") lives at ";
        address.display();
        cout << endl;
    }
};
class Driver : public Person {
private:
    string licenseId;
public:
    Driver(string name, int age, Address a, string licenseId)
        : Person(name, age, a), licenseId(licenseId) {}
    string getLicense() const { return licenseId; }
    void display() const override {
        cout << "Driver: ";
        Person::display();
        cout << "License: " << licenseId << endl;
    }
};
class Commuter : public Person {
public:
    Commuter(string name, int age, Address a)
        : Person(name, age, a) {}
    void display() const override {
        cout << "Commuter: ";
        Person::display();
    }
};
class Engine {
private:
    int horsepower;
    float fuelConsumption;
public:
    Engine(int hp = 100, float fuel = 5.0f)
        : horsepower(hp), fuelConsumption(fuel) {}
    void display() const {
        cout << horsepower << " HP, " << fuelConsumption << " L/100km";
    }
};
class Mosquito {
public:
    void buzz() {
        cout << "Buzz Buzz... 🦟" << endl;
    }
};
class Car {
private:
    string model;
    Engine engine;
    Driver* driver;   
public:
    Car(string model, Engine e, Driver* driver = nullptr)
        : model(model), engine(e), driver(driver) {}
    void setDriver(Driver* d) { driver = d; }
    void display() const {
        cout << "Car model: " << model << "\nEngine: ";
        engine.display();
        cout << "\nDriver: ";
        if (driver) driver->display();
        else cout << "No driver.\n";
    }
};
class Bus {
private:
    int number;
    Engine engine; 
    Driver* driver;  
    vector<Commuter> passengers;
    vector<Mosquito> mosquitoes;
public:
    Bus(int number, Engine eng, Driver* d = nullptr)
        : number(number), engine(eng), driver(d) {}
    void setDriver(Driver* d) { driver = d; }
    void addPassenger(const Commuter& c) {
        passengers.push_back(c);
    }
    void addMosquito() {
        mosquitoes.push_back(Mosquito());
    }
    void display() const {
        cout << "Bus #" << number << "\nEngine: ";
        engine.display();
        cout << "\nDriver: ";
        if (driver) driver->display();
        else cout << "No driver.\n";
        cout << "\nPassengers:\n";
        for (auto& p : passengers)
            p.display();
        cout << "\nMosquitoes count: " << mosquitoes.size() << endl;
    }
};
class BusStation {
private:
    string name;
    Address address;
    vector<Bus> buses;
public:
    BusStation(string name, Address a)
        : name(name), address(a) {}
    void addBus(const Bus& b) { buses.push_back(b); }
    void display() const {
        cout << "\n=== Bus Station: " << name << " ===\nAddress: ";
        address.display();
        cout << "\nBuses:\n";
        for (auto& b : buses)
            b.display();
    }
};
int main() {
    Address a1("Main Street", 10);
    Address a2("Central Avenue", 20);

    Driver d1("John", 45, a1, "XYZ123");
    Driver d2("Alice", 38, a2, "ABC777");

    Commuter c1("Bob", 30, a1);
    Commuter c2("Clara", 22, a2);

    Engine e1(200, 8.5f);
    Engine e2(150, 6.0f);

    Car car("Toyota", e1, &d1);

    Bus bus1(101, e2, &d2);
    bus1.addPassenger(c1);
    bus1.addPassenger(c2);
    bus1.addMosquito();
    bus1.addMosquito();

    BusStation station("Downtown Station", Address("Station Blvd", 5));
    station.addBus(bus1);

    car.display();
    station.display();

    return 0;
}
