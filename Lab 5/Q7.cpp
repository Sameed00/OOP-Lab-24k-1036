#include <iostream>
using namespace std;

class MenuItems {
private:
    string name;
    float price;

public:
    MenuItems() : name(""), price(0.0) {}
    MenuItems(string n, float p) : name(n), price(p) {}
    
    string getName() const { return name; }
    float getPrice() const { return price; }

    void displayItem() const {
        cout << name << " --- " << price << " Rs" << endl;
    }
};

class Menu {
private:
    static const int max = 100;
    MenuItems items[max];
    int count;

public:
    Menu(MenuItems list[], int size) : count(size) {
        for (int i = 0; i < size; ++i) {
            items[i] = list[i];
        }
    }

    void addItem(const MenuItems &item) {
        if (count < max) {
            items[count++] = item;
        } else {
            cout << "Menu is full!\n";
        }
    }

    void removeItem(const MenuItems &item) {
        for (int i = 0; i < count; ++i) {
            if (items[i].getName() == item.getName()) {
                for (int j = i; j < count - 1; ++j) {
                    items[j] = items[j + 1];
                }
                --count;
                cout << "Item " << item.getName() << " has been removed from the menu\n";
                return;
            }
        }
        cout << "Item " << item.getName() << " does not exist in menu\n";
    }

    void displayMenu() const {
        cout << "\nMenu:\n";
        for (int i = 0; i < count; ++i) {
            items[i].displayItem();
        }
    }

    const MenuItems* getItems() const {
        return items;
    }

    int getItemCount() const {
        return count;
    }
};

class Payment {
private:
    double amount;

public:
    Payment(double amt) : amount(amt) {}

    void displayPayment() const {
        cout << "Total Payment: " << amount << " Rs" << endl;
    }
};

class Order {
private:
    static const int maxOrders = 10;
    MenuItems ordered[maxOrders];
    int orderCount;
    Payment payment;

public:
    Order(MenuItems o[], int size) : orderCount(size), payment(calculateTotal(o, size)) {
        for (int i = 0; i < orderCount; ++i) {
            ordered[i] = o[i];
        }
    }

    double calculateTotal(MenuItems o[], int size) {
        double cost = 0;
        for (int i = 0; i < size; ++i) {
            cost += o[i].getPrice();
        }
        return cost;
    }

    void displayOrder() const {
        cout << "\nOrder Summary:\n";
        for (int i = 0; i < orderCount; ++i) {
            ordered[i].displayItem();
        }
        payment.displayPayment();
    }
};

class RestaurantOrderingSystem {
private:
    Menu menu;

public:
    RestaurantOrderingSystem(MenuItems items[], int count) : menu(items, count) {}

    void addMenuItem(const MenuItems &item) {
        menu.addItem(item);
    }

    void removeMenuItem(const MenuItems &item) {
        menu.removeItem(item);
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    Order placeOrder(const string itemNames[], int size) {
        MenuItems orderedItems[size];
        int count = 0;
        const MenuItems* menuItems = menu.getItems();
        int menuCount = menu.getItemCount();

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < menuCount; ++j) {
                if (menuItems[j].getName() == itemNames[i]) {
                    orderedItems[count++] = menuItems[j];
                    break;
                }
            }
        }
        return Order(orderedItems, count);
    }
};

int main() {
    MenuItems initialItems[] = {
        MenuItems("Burger", 500),
        MenuItems("Pizza", 800),
        MenuItems("Pasta", 600)
    };
    int initialItemCount = sizeof(initialItems) / sizeof(initialItems[0]);
    
    RestaurantOrderingSystem system(initialItems, initialItemCount);
    
    system.displayMenu();
    
    system.removeMenuItem(MenuItems("Pizza", 800));0
    system.displayMenu();
    
    string orderItems[] = {"Burger", "Pasta"};
    Order order = system.placeOrder(orderItems, 2);
    order.displayOrder();
    
    return 0;
}
