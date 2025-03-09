#include <iostream>
using namespace std;

class Engine{
	private:
		int HP;
	
	public:
		Engine(int h): HP(h){}
		
		void setHP(int h){
			HP=h;
		}
		int getHP(){return HP;}
};

class Headlights{
	private:
		int brightness;
		string name;
	
	public:
		Headlights(int b,string n):brightness(b),name(n){}
		
		void setB(int b){
			brightness=b;
		}
		void setName(string n){
			name=n;
		}
		
		int getB(){return brightness;}
		string getName(){return name;}	
};

class Documents{
	private:
		string owner,model;
		int year;
	
	public:
		Documents(string o, string m, int y): owner(o) ,model(m), year(y){}
		
		void setOwner(string o){
			owner=o;
		}	
		void setModel(string m){
			model=m;
		}
		void setYear(int y){
			year=y;
		}
		
		string getOwner(){return owner;}
		string getModel(){return model;}
		int getYear(){return year;}
};
class Car{
	private:
		Documents *doc;	//aggregation(can exist independently)
		Headlights hl;	//these 2 are composition as they cannot exist independently so they are not pointers
		Engine eng;
		
	public:
		Car(Documents *d, Headlights h, Engine e):doc(d), hl(h), eng(e){}
		
		void setDoc(Documents *d){	doc=d;}
		void setHl(Headlights h){ hl=h;}
		void setEng(Engine e){ eng = e;}
		
		~Car(){delete doc; //need to delete this as it is a pointer and can exist independently
		cout<<"Deleted, destructor called.";}
		
		void showDetails(){
			cout<<"Car details: \n";
			cout<<"Owner: "<<doc->getOwner()<<" , Model: "<<doc->getModel()<<" , Year: "<<doc->getYear()<<endl;
			cout<<"Engine HP: "<<eng.getHP()<<endl;
			cout<<"Headlights: "<<hl.getName()<<" , Brightness: "<<hl.getB()<<endl;
		}
};

int main(){
	Documents *doc1 = new Documents("Sameed Imran","Ferrari", 2020);
	Engine eng1(500);
	Headlights h1(800,"LED");
	
	Car c1(doc1,h1,eng1);
	c1.showDetails();
	
}
