#include <iostream>
using namespace std;

class PaymentMethod{
	protected:
		double amount;
	public:
		PaymentMethod(double a):amount(a){}
		virtual void processPayment	(double a)=0;
};

class CreditCard:public PaymentMethod{
	private:
		string cardNum;
	public:
		CreditCard(double a, string c):PaymentMethod(a),cardNum(c){}
		void processPayment(double a)override {
			cout<<"Amount deducted: "<<a<<" from Account: "<<cardNum<<endl;
		}
};

class DigitalWallet:public PaymentMethod{
	private:
		double balance;
	public: 
		DigitalWallet(double a,double b):PaymentMethod(a),balance(b){}
		void processPayment(double a)override{
			if(balance>=a){
				balance-=a;
				cout<<"New balance: "<<balance<<endl;
			}
			else cout<<"Insufficient funds, please try again\n";
		}		
		
};

int main(){
	CreditCard c1(100,"12345");
	DigitalWallet d1(500,1000);
	
	c1.processPayment(150);
	d1.processPayment(200);
}
