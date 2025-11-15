#include <bits/stdc++.h>
using namespace std;
class Product {
protected:
    int id;
    string name;
    double price;
public:
    Product(int id, const string& name, double price)
        : id(id), name(name), price(price) {}
    virtual ~Product() = default;
    int getId() const { return id; }
    const string& getName() const { return name; }
    double getPrice() const { return price; }
    virtual string getType() const { return "Product"; }
    virtual void print() const {
        cout << "[" << getType() << "] "
             << "id=" << id << ", "
             << "nume=" << name << ", "
             << "pret=" << price;
    }
};
class Shoe : public Product {
    int size;
    string color;
public:
    Shoe(int id, const string& name, double price, int size, const string& color)
        : Product(id, name, price), size(size), color(color) {}
    string getType() const override { return "Shoe"; }
    void print() const override {
        Product::print();
        cout << ", marime=" << size << ", culoare=" << color;
    }
};
class Toy : public Product {
    int minAge;
public:
    Toy(int id, const string& name, double price, int minAge)
        : Product(id, name, price), minAge(minAge) {}
    string getType() const override { return "Toy"; }
    void print() const override {
        Product::print();
        cout << ", minAge=" << minAge;
    }
};
class Department {
    string name;
    vector<Product*> products;
public:
    Department(const string& name = "") : name(name) {}
    const string& getName() const { return name; }
    //adaugare un produs
    void addProduct(Product* p) {
        if (p) products.push_back(p);
    }
    //adaugare mai multe produse
    void addProducts(const vector<Product*>& lista) {
        for (auto p : lista) {
            if (p) products.push_back(p);
        }
    }
    // cautam un produs dupa nume in departament
    Product* findProductByName(const string& prodName) const {
        for (auto p : products) {
            if (p->getName() == prodName) {
                return p;
            }
        }
        return nullptr;
    }
    // eliminam un produs dupa nume (prima aparitie sau toate)
    bool removeProductByName(const string& prodName, bool removeAll = false) {
        bool removed = false;
        auto it = products.begin();
        while (it != products.end()) {
            if ((*it)->getName() == prodName) {
                it = products.erase(it);
                removed = true;
                if (!removeAll) break;
            } else {
                ++it;
            }
        }
        return removed;
    }
    // toate produsele sortate dupa nume
    vector<Product*> getProductsSortedByName() const {
        vector<Product*> result = products;
        sort(result.begin(), result.end(),
             [](Product* a, Product* b) {
                 return a->getName() < b->getName();
             });
        return result;
    }
    // toate produsele sortate dupa pret
    vector<Product*> getProductsSortedByPrice() const {
        vector<Product*> result = products;
        sort(result.begin(), result.end(),
             [](Product* a, Product* b) {
                 return a->getPrice() < b->getPrice();
             });
        return result;
    }
    static void printProductList(const vector<Product*>& lista) {
        for (auto p : lista) {
            p->print();
            cout << "\n";
        }
    }
    const vector<Product*>& getAllProducts() const {
        return products;
    }
};
class Order {
    int id;
    vector<Product*> items;
public:
    Order(int id = 0) : id(id) {}
    int getId() const { return id; }
    void addProduct(Product* p) {
        if (p) items.push_back(p);
    }
    const vector<Product*>& getItems() const { return items; }
    double getTotal() const {
        double sum = 0;
        for (auto p : items) {
            sum += p->getPrice();
        }
        return sum;
    }
    void print() const {
        cout << "Order #" << id << " (total=" << getTotal() << "):\n";
        for (auto p : items) {
            cout << "   ";
            p->print();
            cout << "\n";
        }
    }
};
class Store {
    Department shoesDept;
    Department toysDept;
    vector<Order> orders;
public:
    Store()
        : shoesDept("Shoes"), toysDept("Toys") {}
    Department& getShoesDept() { return shoesDept; }
    Department& getToysDept()  { return toysDept; }
    const Department& getShoesDept() const { return shoesDept; }
    const Department& getToysDept()  const { return toysDept; }
    void addOrder(const Order& ord) {
        orders.push_back(ord);
    }
    const vector<Order>& getOrders() const {
        return orders;
    }
    Product* findProductInStoreByName(const string& prodName) const {
        Product* p = shoesDept.findProductByName(prodName);
        if (p) return p;
        return toysDept.findProductByName(prodName);
    }
    vector<Product*> searchProductInOrdersByName(const string& prodName) const {
        vector<Product*> found;
        for (const auto& ord : orders) {
            for (auto p : ord.getItems()) {
                if (p->getName() == prodName) {
                    found.push_back(p);
                }
            }
        }
        return found;
    }
    double computeTotalOrdersValue() const {
        double total = 0;
        for (const auto& ord : orders) {
            total += ord.getTotal();
        }
        return total;
    }
};
int main() {
    Store store;
    Shoe* s1 = new Shoe(1, "AdidasX", 300.0, 42, "black");
    Shoe* s2 = new Shoe(2, "NikeAir", 450.0, 43, "white");
    Toy* t1 = new Toy(3, "CarToy", 50.0, 3);
    Toy* t2 = new Toy(4, "LegoSet", 200.0, 6);
    store.getShoesDept().addProduct(s1);
    store.getShoesDept().addProduct(s2);
    store.getToysDept().addProduct(t1);
    store.getToysDept().addProduct(t2);
    Product* gasit = store.getShoesDept().findProductByName("AdidasX");
    if (gasit) {
        cout << "Produs gasit in Shoes: ";
        gasit->print();
        cout << "\n\n";
    }
    store.getToysDept().removeProductByName("CarToy");
    cout << "Produse Shoes sortate dupa pret:\n";
    auto shoesSortedByPrice = store.getShoesDept().getProductsSortedByPrice();
    Department::printProductList(shoesSortedByPrice);
    cout << "\n";
    cout << "Toate produsele Toys ramase:\n";
    Department::printProductList(store.getToysDept().getAllProducts());
    cout << "\n";
    Order o1(1001);
    o1.addProduct(s1);
    o1.addProduct(t2);
    Order o2(1002);
    o2.addProduct(s2);
    store.addOrder(o1);
    store.addOrder(o2);
    cout << "Afisam comenzile:\n";
    for (const auto& ord : store.getOrders()) {
        ord.print();
        cout << "\n";
    }
    cout << "Cautam produsul 'LegoSet' in comenzile magazinului:\n";
    auto foundInOrders = store.searchProductInOrdersByName("LegoSet");
    Department::printProductList(foundInOrders);
    cout << "\n";
    double totalOrders = store.computeTotalOrdersValue();
    cout << "Valoarea totala a comenzilor = " << totalOrders << "\n";
    delete s1;
    delete s2;
    delete t1;
    delete t2;
    return 0;
}
