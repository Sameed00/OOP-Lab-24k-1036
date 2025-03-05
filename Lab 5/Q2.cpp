#include <iostream>
using namespace std;

class LoanHelper{
	private:
		float loan,amount;
		const double rate;
		int months;
	
	public:
		LoanHelper(double r,float l,int m): rate(r), loan(l), months(m) //use initialiser list for const data types, and dont create default constructor
		{
			if(r<0 || r>0.005){
				cout<<"Re-Enter value for rate of interest between 0%-0.5% (0-0.005). \n";
			}
		}		
		
		void display(){
			amount = (loan/months) * (1+rate);
			cout<<"You have to pay "<<amount<<" every month for "<<months<<" months to repay your loan. \n";
			}
};

int main(){
	LoanHelper l1(0.002,1000,6),l2(1,35,2),l3(0.003,560,4);
	l1.display();
	l2.display();
	l3.display();
}
