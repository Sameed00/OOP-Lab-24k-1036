#include <iostream>
using namespace std;

class Employee{
	private:
		
		int employeeID;
		string name, department;
		double salary;
		
	public:
		Employee(){
			salary = 0.0;
		}
		Employee(int id,string n,string d,double s){
			employeeID = id;
			name = n;
			department = d;
			salary = s;
		}
		void giveBonus(double amount){
			salary += amount;
		}
		bool isManager(){
			if (department == "Management"){
				return true;
			}
		}
		void displayDetails(){
			cout<<"ID: "<<employeeID<<" name: "<<name<<" department: "<<department<<" salary: "<<salary<<endl;
		}
};

int main(){
	Employee e1,e2;
	e1 = Employee(2416,"Sameed","CS",100.35);
	e2 = Employee(100,"Zayan","Management",55);
	cout<<e2.isManager()<<endl;
	e1.giveBonus(20.65);
	e1.displayDetails();
	e2.displayDetails();
	
	
}
