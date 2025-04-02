#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
public:
    Currency(double amt, string code, string symbol, double rate = 1.0) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double convertToBase() = 0;
    virtual void displayCurrency() = 0;
    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    double convertToBase() override {
        return amount * exchangeRate;
    }
    void displayCurrency() override {
        cout << currencySymbol << amount << " " << currencyCode << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "\u20AC", 1.1) {}
    double convertToBase() override {
        return amount * exchangeRate;
    }
    void displayCurrency() override {
        cout << currencySymbol << amount << " " << currencyCode << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs.", 0.0058) {}
    double convertToBase() override {
        return amount * exchangeRate;
    }
    void displayCurrency() override {
        cout << currencySymbol << amount << " " << currencyCode << endl;
    }
};

int main() {
    Currency* c1 = new Dollar(100);
    Currency* c2 = new Euro(100);
    Currency* c3 = new Rupee(100);
    
    c1->displayCurrency();
    cout << "In base currency: " << c1->convertToBase() << endl;
    
    c2->displayCurrency();
    cout << "In base currency: " << c2->convertToBase() << endl;
    
    c3->displayCurrency();
    cout << "In base currency: " << c3->convertToBase() << endl;
    
    delete c1;
    delete c2;
    delete c3;
    return 0;
}
