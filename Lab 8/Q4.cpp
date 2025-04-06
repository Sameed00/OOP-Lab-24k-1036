#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void calculateInterest() {
        cout << "Base interest calculation (not used directly).\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Cash deposited: $" << amount << endl;
    }

    void deposit(string checkNumber, double amount) {
        balance += amount;
        cout << "Check (" << checkNumber << ") deposited: $" << amount << endl;
    }

    void deposit(double amount, string method) {
        balance += amount;
        cout << "Online transfer via " << method << ": $" << amount << endl;
    }

    BankAccount operator+(BankAccount other) {
        return BankAccount("Merged", this->balance + other.balance);
    }

    BankAccount operator-(double amount) {
        return BankAccount(this->accountNumber, this->balance - amount);
    }

    BankAccount operator*(double interestRate) {
        return BankAccount(this->accountNumber, this->balance * (1 + interestRate));
    }

    BankAccount operator/(int parts) {
        return BankAccount(this->accountNumber, this->balance / parts);
    }

    void showDetails() {
        cout << "Account: " << accountNumber << " | Balance: $" << balance << endl;
    }
};

// Savings Account
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void calculateInterest() override {
        double interest = balance * 0.05;
        balance += interest;
        cout << "Interest (5%) added: $" << interest << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount >= 500) {
            balance -= amount;
            cout << "Withdrawn from Savings: $" << amount << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance of $500 required.\n";
        }
    }
};

// Current Account
class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void calculateInterest() override {
        cout << "No interest for Current Account.\n";
    }

    void withdraw(double amount) override {
        if (balance - amount >= -1000) {
            balance -= amount;
            cout << "Withdrawn from Current: $" << amount << endl;
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }
};

int main() {
    SavingsAccount sa("SA123", 1000);
    CurrentAccount ca("CA456", 500);

    sa.showDetails();
    ca.showDetails();

    sa.deposit(200);                              // Cash deposit
    sa.deposit("CHK102", 300);                    // Check deposit
    sa.deposit(150, "Mobile App");                // Online transfer

    sa.withdraw(400);                             // Savings withdrawal with rule
    ca.withdraw(1300);                            // Overdraft allowed in current account

    sa.calculateInterest();                       // 5% Interest
    ca.calculateInterest();                       // No interest

    sa.showDetails();
    ca.showDetails();

    BankAccount total = sa + ca;                  // Add balances
    total.showDetails();

    BankAccount afterWithdraw = total - 300;      // Subtract from balance
    afterWithdraw.showDetails();

    BankAccount afterInterest = sa * 0.05;        // Apply 5% interest
    afterInterest.showDetails();

    BankAccount installment = ca / 3;             // Divide into 3 parts
    installment.showDetails();

    return 0;
}
