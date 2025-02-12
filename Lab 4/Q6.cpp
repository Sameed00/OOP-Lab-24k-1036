#include <iostream>
using namespace std;

class Account{
	private:
		int accountNum;
		string name;
		double balance;
		
	public:
		Account(){
			balance = 0;
		}	
		Account(int num, string n,double b ){
			accountNum = num;
			name = n;
			balance = b;
			
		}
		void deposit(double money){
			balance +=money;
		}
		void withdraw(double money){
			if (money<=balance){
				balance -= money; 
			}
			
		}
		void displayDetails(){
			cout<<"Account num: "<<accountNum<<endl<<"Name: "<<name<<endl<<"Balance: "<<balance<<endl;
		}
};

int main(){
	Account a1,a2;
	a1 = Account(1234,"Sameed",500);
	a2 = Account(100,"Ali",20.5);
	a2.deposit(50.3);
	a1.withdraw(30.5);
	a1.displayDetails();
	a2.displayDetails();
}
