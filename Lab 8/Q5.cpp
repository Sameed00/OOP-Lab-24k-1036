#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    float price;
    int quantity;

public:
    Product(int id = 0, float p = 0.0, int q = 1) : productID(id), price(p), quantity(q) {}
    virtual float calculatePrice() const = 0;

    void applyDiscount(float percentage) {
        price -= price * (percentage / 100.0);
    }

    void applyDiscount(int fixedAmount) {
        price -= fixedAmount;
        if (price < 0) price = 0;
    }

    void applyDiscount(bool buyOneGetOneFree) {
        if (buyOneGetOneFree && quantity >= 2) {
            int freeItems = quantity / 2;
            quantity -= freeItems;
        }
    }

    int getID() const { return productID; }
    int getQuantity() const { return quantity; }
    float getPrice() const { return price; }

    void display() const {
        cout << "Product ID: " << productID << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};

class Electronics : public Product {
public:
    Electronics(int id, float p, int q = 1) : Product(id, p, q) {}
    float calculatePrice() const override {
        float taxRate = 0.15f;
        return price * (1 + taxRate) * quantity;
    }
};

class Clothing : public Product {
public:
    Clothing(int id, float p, int q = 1) : Product(id, p, q) {}
    float calculatePrice() const override {
        float taxRate = 0.05f;
        return price * (1 + taxRate) * quantity;
    }
};

class ShoppingCart {
private:
    Product* items[10];
    int itemCount;

public:
    ShoppingCart() : itemCount(0) {}

    void addProduct(Product* p) {
        if (itemCount < 10) {
            items[itemCount++] = p;
        } else {
            cout << "Cart is full!" << endl;
        }
    }

    void displayCart() const {
        for (int i = 0; i < itemCount; ++i) {
            items[i]->display();
        }
    }

    float calculateTotal() const {
        float total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->calculatePrice();
        }
        return total;
    }

    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart merged;
        for (int i = 0; i < itemCount; ++i)
            merged.addProduct(items[i]);
        for (int i = 0; i < other.itemCount; ++i)
            merged.addProduct(other.items[i]);
        return merged;
    }

    ShoppingCart operator-(int id) {
        ShoppingCart updated;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->getID() != id) {
                updated.addProduct(items[i]);
            }
        }
        return updated;
    }

    void operator*(float percentDiscount) {
        for (int i = 0; i < itemCount; ++i) {
            items[i]->applyDiscount(percentDiscount);

