#include <iostream>
using namespace std;

class Vehicle{
	protected:
		string model;
		double rate;
	public:
		Vehicle(string m,double r):model(m),rate(r){}
		virtual double getDailyrate()=0;
		virtual void displayDetails()=0;
};

class Car:public Vehicle{
	public:
		Car(string m,double r):Vehicle(m,r){}
		double getDailyrate(){return rate;}
		void displayDetails(){
			cout<<"Car started\n"<<"Model: "<<model<<", Rate: "<<rate<<endl;
		}
};

class Bike:public Vehicle{
	public:
		Bike(string m, double r):Vehicle(m,r){}
		double getDailyrate(){return rate;}
		void displayDetails(){
			cout<<"Bike started\n"<<"Model: "<<model<<", Rate: "<<rate<<endl;
		}
};

int main(){
	Vehicle *v1;
	Car c1("BMW",500.0);
	Bike b1("Honda",100.20);
	v1=&c1;
	v1->displayDetails();
	v1=&b1;
	v1->displayDetails();
}

