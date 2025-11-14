#include <bits/stdc++.h>
using namespace std;
class Product {
private:
    string name;
    float price;
    bool promo; 
public:
    Product(string name = "NoName", float price = 0, bool promo = false) {
        this->name = name;
        this->price = price;
        this->promo = promo;
    }
    string getName() { return name; }
    float getPrice() { return price; }
    bool isPromo() { return promo; }
    void setName(string name) { this->name = name; }
    void setPrice(float price) { this->price = price; }
    void setPromo(bool promo) { this->promo = promo; }
    void display() {
        cout << name << " - " << price << " lei";
        if (promo) cout << " (PROMO)";
        cout << endl;
    }
};
class Category {
private:
    string name;
    vector<Product> products;
public:
    Category(string name = "General") {
        this->name = name;
    }
    string getName() { return name; }
    void addProduct(Product p) {
        products.push_back(p);
    }
    void removeProduct(string name) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getName() == name) {
                products.erase(products.begin() + i);
                break;
            }
        }
    }
    void updateProduct(string name, float price, bool promo) {
        for (auto &p : products) {
            if (p.getName() == name) {
                p.setPrice(price);
                p.setPromo(promo);
            }
        }
    }
    vector<Product> getProducts() { return products; }
};
class OnlineShop {
private:
    vector<Category> categories;
public:
    void addCategory(Category c) {
        categories.push_back(c);
    }
    void removeCategory(string name) {
        for (int i = 0; i < categories.size(); i++) {
            if (categories[i].getName() == name) {
                categories.erase(categories.begin() + i);
                break;
            }
        }
    }
    void displayAllProducts() {
        cout << "\nProduse în magazin\n";
        for (auto &cat : categories) {
            cout << "\nCategoria: " << cat.getName() << endl;
            for (auto &p : cat.getProducts()) {
                p.display();
            }
        }
    }
    void displayPromoProducts() {
        cout << "\nProduse la PROMO\n";
        for (auto &cat : categories) {
            for (auto &p : cat.getProducts()) {
                if (p.isPromo())
                    p.display();
            }
        }
    }
    void search(string name = "", float price = -1, string category = "") {
        cout << "\nRezultate căutare\n";
        for (auto &cat : categories) {
            if (category != "" && cat.getName() != category) continue;
            for (auto &p : cat.getProducts()) {
                bool match = true;
                if (name != "" && p.getName() != name)
                    match = false;
                if (price != -1 && p.getPrice() != price)
                    match = false;
                if (match)
                    p.display();
            }
        }
    }
};
int main() {
    OnlineShop shop;
    Category electronics("Electronics");
    Category food("Food");
    electronics.addProduct(Product("Laptop", 3500, true));
    electronics.addProduct(Product("Mouse", 50, false));
    food.addProduct(Product("Pizza", 25, false));
    food.addProduct(Product("Burger", 20, true));
    shop.addCategory(electronics);
    shop.addCategory(food);
    shop.displayAllProducts();
    shop.displayPromoProducts();
    shop.search("Laptop");              
    shop.search("", 20);               
    shop.search("", -1, "Electronics");
    return 0;
}
