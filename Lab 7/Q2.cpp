#include <iostream>
#include <cmath>
using namespace std;

class Shape{
	protected:
		float pos;
		string color;
		float borderThickness;
		float area,perimeter;
	public:
		Shape(float p,string c):pos(p),color(c){}
		Shape(float p,string c, float bT):pos(p),color(c),borderThickness(bT){}
		
		virtual void draw(){
			cout<<"Drawing shape...\n";}
		virtual void calculateArea(){
		cout<<"Area = ...\n";}
		virtual void calculatePerimeter(){
		cout<<"Perimeter = ...\n";}
			
			
};
class Circle:public Shape{
	private:
		float radius,center;

	public:
		Circle(float r, float c):Shape(c,"Red"),radius(r),center(c){}
		void draw() override {
			cout<<"Drawing a circle...\n";
		}	
		void calculateArea() override {
			area = (3.14159265) * radius * radius;
			cout<<"Area = "<<area<<endl;
		}
		void calculatePerimeter() override {
			perimeter = 2 * (3.14159265) * radius;
			cout<<"Perimeter = "<<perimeter<<endl;
		}
};

class Rectangle:public Shape{
	private:
		float width,height,topLeft;
	public:
		Rectangle(float w,float h,float l):Shape(l,"Blue"),width(w),height(h),topLeft(l){}
		void draw() override {
			cout<<"Drawing a rectangle...\n";
		}	
		void calculateArea() override {
			area=width*height;
			cout<<"Area = "<<area<<endl;
		}
		void calculatePerimeter() override {
			perimeter= 2*(width+height);
			cout<<"Perimeter = "<<perimeter<<endl;
		}
};

class Polygon:public Shape{
	private:
		int sides;
		float length;
		float apoethem;
	public:
		Polygon(int s,float l):Shape(2,"Grey"),sides(s),length(l){}	
		void draw() override {
			cout<<"Drawing a polygon with sides: "<<sides<<endl;
		}
		void calculateArea() override {
			apoethem = (length) / (2 * tan(3.14159265/sides));
			area = (0.5) * apoethem * (sides*length);
			cout<<"Area = "<<area<<endl;
		}
		void calculatePerimeter() override {
			perimeter= sides*length;
			cout<<"Perimeter = "<<perimeter<<endl;
		}
		
};

int main(){
	Shape *s1;
	Circle c1(5.5,0.2);
	Rectangle r1(2.5,7,1);
	Polygon p1(6,3.5);
	
	s1=&c1;
	s1->draw();
	s1->calculateArea();
	s1->calculatePerimeter();
	
	s1=&r1;
	s1->draw();
	s1->calculateArea();
	s1->calculatePerimeter();
	
	s1=&p1;
	s1->draw();
	s1->calculateArea();
	s1->calculatePerimeter();
}
