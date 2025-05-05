#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
	ofstream out1("info.txt",ios::out);
	out1<<"C++ is a powerful programming language.";
	out1.close();
	fstream out2("info.txt",ios::in|ios::out);
	streampos g1= out2.tellg();
	streampos p1 = out2.tellp();
	cout<<"Get pointer: "<<g1<<"\nPut pointer: "<<p1<<endl;
	out2.seekg(9);
	string line;
	while(getline(out2,line)){
		cout<<line;
	}
	cout<<endl;
	out2.clear();
	out2.seekp(9);
	out2.write("dynamics",8);
	out2.seekg(0);
	while(getline(out2,line)){
		cout<<line;
	}
	cout<<endl;
	out2.clear();
	g1= out2.tellg();
	p1 = out2.tellp();
	cout<<"Get pointer: "<<g1<<"\nPut pointer: "<<p1<<endl;
}
