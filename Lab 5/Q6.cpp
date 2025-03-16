#include <iostream>
using namespace std;

class Graphics{
	private:
		string name;
		int version;
	
	public:
		Graphics(string n, int v): name(n), version(v){
		cout<<"Graphics engine name: "<<name<<", Version: "<<version<<endl;
		}
				
};

class Physics{
	private:
		string name;
		int version;
		
	public:
		Physics(string n, int v): name(n), version(v){
			cout<<"Physics engine name: "<<name<<", Version: "<<version<<endl;
		}	
};
class GameEngine{
	private:
		string name;
		Graphics gEngine;
		Physics pEngine;
	public:
		GameEngine(string n, string n1,int v1, string n2, int v2): name(n), gEngine(n1, v1), pEngine(n2, v2){
			cout<<"Game engine created, Name: "<<name<<endl;
		} 		
	
};

int main(){
	GameEngine g1("Unity", "FrostBite",2022,"NewPhysics",2024);
}

