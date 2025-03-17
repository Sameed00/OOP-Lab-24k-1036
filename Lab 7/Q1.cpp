#include <iostream>
#include <string>
using namespace std;


class Account {
protected:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    Account(string name, int accNum, double bal) : accountHolderName(name), accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
    }

    virtual bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        return true;
    }

    virtual void calculateInterest() = 0; 
    virtual void printStatement() = 0;   

    void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << endl;
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string name, int accNum, double bal, double rate, double minBal)
        : Account(name, accNum, bal), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: " << interest << ". New Balance: " << balance << endl;
    }

    void printStatement() override {
        cout << "Savings Account Statement:\nBalance: " << balance << "\nInterest Rate: " << interestRate << "%" << endl;
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(string name, int accNum, double bal) : Account(name, accNum, bal) {}

    void calculateInterest() override {
        cout << "Checking accounts do not earn interest." << endl;
    }

    void printStatement() override {
        cout << "Checking Account Statement:\nBalance: " << balance << endl;
    }
};


class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityPeriod; 

public:
    FixedDepositAccount(string name, int accNum, double bal, double rate, int period)
        : Account(name, accNum, bal), fixedInterestRate(rate), maturityPeriod(period) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100) * (maturityPeriod / 12.0);
        balance += interest;
        cout << "Fixed Deposit Interest added: " << interest << ". New Balance: " << balance << endl;
    }

    void printStatement() override {
        cout << "Fixed Deposit Account Statement:\nBalance: " << balance << "\nFixed Interest Rate: " << fixedInterestRate << "%\nMaturity Period: " << maturityPeriod << " months" << endl;
    }
};

int main() {
    SavingsAccount sa("John Doe", 101, 5000, 5, 1000);
    CheckingAccount ca("Jane Doe", 102, 2000);
    FixedDepositAccount fda("Alice Smith", 103, 10000, 6, 12);

    cout << "--- Savings Account ---" << endl;
    sa.deposit(1000);
    sa.withdraw(2000);
    sa.calculateInterest();
    sa.printStatement();

    cout << "\n--- Checking Account ---" << endl;
    ca.deposit(500);
    ca.withdraw(2500);
    ca.calculateInterest();
    ca.printStatement();

    cout << "\n--- Fixed Deposit Account ---" << endl;
    fda.calculateInterest();
    fda.printStatement();

    return 0;
}
