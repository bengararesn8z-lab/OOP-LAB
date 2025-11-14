#include <bits/stdc++.h>
using namespace std;
class User {
private:
    string username;
    string password;
    float balance;
public:
    User(string username, string password, float balance = 0) {
        this->username = username;
        this->password = password;
        this->balance = balance;
    }
    string getUsername() { return username; }
    string getPassword() { return password; }
    float getBalance() { return balance; }
    void deposit(float amount) {
        balance += amount;
    }
    bool withdraw(float amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }
};
class BankApp {
private:
    vector<User> users;
    User* loggedUser;
public:
    static int userCount
    BankApp() {
        loggedUser = NULL;
    }
    void addUser(User u) {
        users.push_back(u);
        userCount++;
    }
    bool login(string username, string password) {
        for (auto &u : users) {
            if (u.getUsername() == username && u.getPassword() == password) {
                loggedUser = &u;
                cout << "Login reusit!\n";
                return true;
            }
        }
        cout << "Credentiale gresite!\n";
        return false;
    }
    bool isLogged() {
        if (loggedUser == NULL) {
            cout << "Trebuie sa fii logat pentru aceasta operatie!\n";
            return false;
        }
        return true;
    }
    void deposit(float amount) {
        if (!isLogged()) return;
        loggedUser->deposit(amount);
        cout << "Ai depus " << amount << " lei.\n";
    }
    void withdraw(float amount) {
        if (!isLogged()) return;

        if (!loggedUser->withdraw(amount)) {
            cout << "Fonduri insuficiente!\n";
            return;
        }
        cout << "Ai retras " << amount << " lei.\n";
    }
    void displayBalance() {
        if (!isLogged()) return;
        cout << "Sold curent: " << loggedUser->getBalance() << " lei.\n";
    }
    void displayUserCount() {
        cout << "Numar total de utilizatori: " << userCount << "\n";
    }
};
int BankApp::userCount = 0;
int main() {
    BankApp app;
    app.addUser(User("ana", "1234", 200));
    app.addUser(User("mihai", "abcd", 500));
    app.displayUserCount();
    app.login("ana", "1234");
    app.deposit(100);
    app.withdraw(50);
    app.displayBalance();
    cout << "\nIncercare operatie fara login\n";
    BankApp app2;
    app2.withdraw(100);
    return 0;
}
