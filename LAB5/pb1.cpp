#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Bus;
class BusStation;
class Vehicle;
class Car;
class Address {
private:
    string street;
    int number;
    string city;
public:
    Address(const string& street = "", int number = 0, const string& city = "")
        : street(street), number(number), city(city) {}
    const string& getStreet() const { return street; }
    int getNumber() const { return number; }
    const string& getCity() const { return city; }
    bool operator==(const Address& other) const {
        return street == other.street &&
               number == other.number &&
               city == other.city;
    }
};
class Mosquito {
private:
    int id;
public:
    Mosquito(int id = 0) : id(id) {}
    int getId() const { return id; }
};
class Apartment {
private:
    Address address;
    vector<Mosquito*> mosquitoes;
public:
    Apartment(const Address& addr = Address()) : address(addr) {}
    const Address& getAddress() const { return address; }
    void addMosquito(Mosquito* m) {
        if (m) mosquitoes.push_back(m);
    }
    bool removeMosquitoById(int id, Mosquito*& outPtr) {
        for (size_t i = 0; i < mosquitoes.size(); ++i) {
            if (mosquitoes[i]->getId() == id) {
                outPtr = mosquitoes[i];
                mosquitoes.erase(mosquitoes.begin() + i);
                return true;
            }
        }
        return false;
    }
    bool hasMosquito(int id) const {
        for (auto m : mosquitoes) {
            if (m->getId() == id) return true;
        }
        return false;
    }
};
class Person {
protected:
    string name;
    Apartment* apartment;
public:
    Person(const string& name = "")
        : name(name), apartment(nullptr) {}
    virtual ~Person() = default;
    const string& getName() const { return name; }
    void setApartment(Apartment* a) { apartment = a; }
    Apartment* getApartment() const { return apartment; }
};
class Commuter : public Person {
public:
    Commuter(const string& name = "") : Person(name) {}
};
class Student : public Commuter {
private:
    string faculty;
public:
    Student(const string& name = "", const string& faculty = "")
        : Commuter(name), faculty(faculty) {}
};
class Driver : public Person {
private:
    string licenseId;
public:
    Driver(const string& name = "", const string& licenseId = "")
        : Person(name), licenseId(licenseId) {}
    const string& getLicenseId() const { return licenseId; }
};
class Engine {
private:
    bool started;
public:
    Engine() : started(false) {}
    void start() {
        started = true;
        cout << "Motor pornit.\n";
    }
    void stop() {
        started = false;
        cout << "Motor oprit.\n";
    }
    bool isStarted() const { return started; }
};
class Vehicle {
protected:
    string registrationNumber;
    Engine engine;
    Driver* driver;
    vector<Commuter*> passengers;
    vector<Mosquito*> mosquitoes;
public:
    Vehicle(const string& reg = "")
        : registrationNumber(reg), driver(nullptr) {}
    virtual ~Vehicle() = default;
    void setDriver(Driver* d) { driver = d; }
    Driver* getDriver() const { return driver; }
    virtual void startEngine() {
        engine.start();
    }
    void addPassenger(Commuter* c) {
        if (c) passengers.push_back(c);
    }
    int getPassengerCount() const {
        return (int)passengers.size();
    }
    bool hasPassenger(Commuter* c) const {
        return find(passengers.begin(), passengers.end(), c) != passengers.end();
    }
    void addMosquito(Mosquito* m) {
        if (m) mosquitoes.push_back(m);
    }
    bool hasMosquito(int id) const {
        for (auto m : mosquitoes) {
            if (m->getId() == id) return true;
        }
        return false;
    }
    const string& getRegistrationNumber() const { return registrationNumber; }
};
class Bus : public Vehicle {
private:
    int number;
    vector<BusStation*> route;
public:
    Bus(int number = 0, const string& reg = "")
        : Vehicle(reg), number(number) {}
    int getNumber() const { return number; }
    void addStation(BusStation* st) {
        if (st) route.push_back(st);
    }
    const vector<BusStation*>& getRoute() const {
        return route;
    }
};
class Car : public Vehicle {
public:
    Car(const string& reg = "") : Vehicle(reg) {}
};
class BusStation {
private:
    string name;
    Address address;
    vector<Bus*> busesStoppingHere;
    vector<Commuter*> peopleWaiting;
public:
    BusStation(const string& name = "", const Address& addr = Address())
        : name(name), address(addr) {}
    const string& getName() const { return name; }
    const Address& getAddress() const { return address; }
    void addBus(Bus* b) {
        if (b) busesStoppingHere.push_back(b);
    }
    const vector<Bus*>& getBuses() const {
        return busesStoppingHere;
    }
    void addCommuter(Commuter* c) {
        if (c) peopleWaiting.push_back(c);
    }
    int getCommuterCount() const {
        return (int)peopleWaiting.size();
    }
};
void startBusEngine(Bus& bus) {
    bus.startEngine();
}
int getCommuterCountInBus(const Bus& bus) {
    return bus.getPassengerCount();
}
int getCommuterCountInStation(const BusStation& st) {
    return st.getCommuterCount();
}
const vector<Bus*>& getBusesStoppingInStation(const BusStation& st) {
    return st.getBuses();
}
const vector<BusStation*>& getStationsForBus(const Bus& bus) {
    return bus.getRoute();
}
void moveApartmentFromPersonToStudent(Person& p, Student& s) {
    Apartment* ap = p.getApartment();
    s.setApartment(ap);
    p.setApartment(nullptr);
}
void addStudentToStationBusAndCar(Student* st, BusStation& station, Bus& bus, Car& car) {
    if (!st) return;
    station.addCommuter(st);
    bus.addPassenger(st);
    car.addPassenger(st);
}
bool moveMosquitoFromApartmentToVehicle(Apartment& ap, int mosquitoId, Vehicle& v) {
    Mosquito* m = nullptr;
    if (ap.removeMosquitoById(mosquitoId, m)) {
        v.addMosquito(m);
        return true;
    }
    return false;
}
bool isMosquitoInApartment(const Apartment& ap, int mosquitoId) {
    return ap.hasMosquito(mosquitoId);
}
bool isMosquitoInVehicle(const Vehicle& v, int mosquitoId) {
    return v.hasMosquito(mosquitoId);
}
Student* findStudentByAddress(const vector<Student*>& allStudents, const Address& addr) {
    for (auto st : allStudents) {
        Apartment* ap = st->getApartment();
        if (ap && ap->getAddress() == addr) {
            return st;
        }
    }
    return nullptr;
}
bool isStudentInBusDrivenBy(const vector<Student*>& allStudents,
                            const Address& addr,
                            const Driver& driver,
                            const Bus& bus) {
    Student* st = findStudentByAddress(allStudents, addr);
    if (!st) return false;
    if (bus.getDriver() != &driver) return false;
    return bus.hasPassenger(st);
}
int main() {
    Address addr1("Str. Mare", 10, "Craiova");
    Address addr2("Str. Mica", 5, "Craiova");
    Apartment ap1(addr1);
    Apartment ap2(addr2);
    Mosquito m1(101);
    Mosquito m2(102);
    ap1.addMosquito(&m1);
    ap2.addMosquito(&m2);
    Person p("Ion");
    p.setApartment(&ap1);
    Student s("Andrei", "AC");
    s.setApartment(&ap2);
    Driver d("Soferu", "B123456");
    Bus bus(1, "B-01-XYZ");
    bus.setDriver(&d);
    Car car("DJ-99-ABC");
    BusStation st("Statie Centrala", addr1);
    st.addBus(&bus);
    startBusEngine(bus);
    moveApartmentFromPersonToStudent(p, s);
    addStudentToStationBusAndCar(&s, st, bus, car);
    moveMosquitoFromApartmentToVehicle(*s.getApartment(), 102, bus);
    cout << "Tantar 102 in bus? "
         << (isMosquitoInVehicle(bus, 102) ? "DA" : "NU") << "\n";
    vector<Student*> totiStudentii = { &s };
    bool ok = isStudentInBusDrivenBy(totiStudentii, addr2, d, bus);
    cout << "Studentul de la addr2 e in busul condus de d? "
         << (ok ? "DA" : "NU") << "\n";
    return 0;
}
