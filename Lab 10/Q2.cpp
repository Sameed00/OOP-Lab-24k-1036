#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
	string name,email,summary;
	int exp;
	
	cout<<"Enter name:\nEnter email:\nEnter summary:\nEnter experience years:\n";
	getline(cin,name);
	getline(cin,email);
	getline(cin,summary);
	cin>>exp;
	cin.ignore();
	
	ofstream file("resume.txt",ios::trunc);
	file<<name<<email<<summary<<exp;
	file.close();
	
	ifstream inFile("resume.txt");
	string line;
	while(getline(inFile,line)){
		cout<<line<<endl;
	}
	inFile.close();
}
