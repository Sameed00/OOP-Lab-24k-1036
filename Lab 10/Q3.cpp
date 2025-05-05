#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
	ifstream ch1("chapter1.txt");
	ifstream ch2("chapter2.txt");
	
	ofstream b1("book.txt",ios::app);
	string line;
	while(getline(ch1,line)){
		b1<<line<<endl;
	}
	b1<<endl;
	while(getline(ch2,line)){
		b1<<line<<endl;
	}
	string line2;
	ifstream b2("book.txt");
	while(getline(b2,line2)){
		cout<<line2<<endl;
	}
}
