#include <iostream>
using namespace std;

class BankAccount{
	private:
		int accountNumber;
		float balance;
		string accountHolderName;
	
	public:
		BankAccount(int aN, float b, string hN) : accountNumber(aN) , balance(b) , accountHolderName(hN){}
		
		void deposit(double amount){
			balance+=amount;
		}		
		void withdraw(double amount){
			if (balance>=amount){
				balance-=amount;
			}
			else cout<<"Invalid entry, insufficient funds in account. \n";
		}
		void display(){
			cout<<"Account Number: "<<accountNumber<<"\nHolder Name: "<<accountHolderName<<"\nBalance: "<<balance<<"\n\n";
		}
};

int main(){
	BankAccount Accounts[]{
	BankAccount(1234,1000,"Sameed"),
	BankAccount(2043,240.89,"Ahmed"),
	BankAccount(1211,3900,"Mustafa")
	};
	for(BankAccount &bA : Accounts){
		bA.display();
	}
	Accounts[1].deposit(500);
	Accounts[1].display();
	Accounts[1].withdraw(200);
	Accounts[1].display();
}
