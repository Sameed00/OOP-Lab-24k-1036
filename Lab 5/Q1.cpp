#include<iostream>
using namespace std;

class Square{
	private:
		float sideLength,area;
		static float allareas;
	
	public:
		Square(){}
		Square(float sL){
			sideLength = sL;
		}
		void calArea(){;
		area = sideLength*sideLength;
		allareas+=area;
		}
		void setSideLength(float sL){
			sideLength=sL;
		}
		float getSideLength(){
			return sideLength;
		}
		float getArea(){
			return area;
		}
		float getAllAreas(){
			return allareas;
		}
};

float Square::allareas = 0.0f;

int main(){
	Square s1(5.5),s2(2.9),s3(7);
	s1.calArea();
	cout<<s1.getArea()<<" "<<s1.getAllAreas()<<endl;
	s2.calArea();
	cout<<s2.getArea()<<" "<<s2.getAllAreas()<<endl;
	s3.calArea();
	cout<<s3.getArea()<<" "<<s3.getAllAreas()<<endl;
	
}
