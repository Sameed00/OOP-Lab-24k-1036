# include <iostream>
using namespace std;

class Student{
	
	private :
		
			int studentID;
			string name;
			int age;
			char grade;
			
	public:
		
		Student(){
			grade ='N';
			
		}
		
		Student(int id,string namep,int agep,char gradep){
			this->studentID =id;
			this->name = namep;
			this->age = agep;
			this->grade = gradep;
			
		}
		
		void promote_student(){
			if (grade!='A')
			grade--;
			
		}
		
		bool isEligibleForScholarship(){
			if (grade=='A'){
				return true;
				
			}
			else{
				return false;
				
			}
		}
		
		void displayDetails(){
			cout <<"==========================="<<endl;
			cout <<"*******Student Info********"<<endl;
			cout <<"Student Name: "<<name<<endl;
			cout <<"Student ID: "<<studentID<<endl;
			cout <<"Age: "<<age<<endl;
			cout <<"Your Grade: "<<grade<<endl;
			
		}
};


int main(){
	bool check;
	Student s1;
	Student s2;
	Student s3(804,"burair hyder",18,'B');
	s3.promote_student();
	check = s3.isEligibleForScholarship();
	if (check==true){
		cout <<"You are eligbile for scholarship in Cambridge University"<<endl;
	}
	else{
		cout<<"TrY hard again for scholarship"<<endl;
	}
	s3.displayDetails();

	

}
