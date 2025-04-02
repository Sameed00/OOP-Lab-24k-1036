#include <iostream>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    virtual void displayInfo() = 0;
    virtual void updateInfo(string newAddress, string newPhone) {
        address = newAddress;
        phoneNumber = newPhone;
    }
    string getName() { return name; }
    virtual ~Person() {}
};

class Student : public Person {
private:
    int coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, int cE, double g, int eY)
        : Person(n, i, a, p, e), coursesEnrolled(cE), GPA(g), enrollmentYear(eY) {}
    void displayInfo() override {
        cout << "Student: " << name << ", GPA: " << GPA << ", Enrolled: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
private:
    string department;
    int coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, int cT, double s)
        : Person(n, i, a, p, e), department(d), coursesTaught(cT), salary(s) {}
    void displayInfo() override {
        cout << "Professor: " << name << ", Department: " << department << ", Salary: " << salary << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, double s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}
    void displayInfo() override {
        cout << "Staff: " << name << ", Position: " << position << ", Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    Course(string cId, string cN, int cr, string inst, string sch)
        : courseId(cId), courseName(cN), credits(cr), instructor(inst), schedule(sch) {}
    void registerStudent(Student* student) {
        cout << "Registering student " << student->getName() << " for course " << courseName << endl;
    }
    void calculateGrades() {
        cout << "Calculating grades for course " << courseName << endl;
    }
    void displayCourse() {
        cout << "Course: " << courseName << ", Instructor: " << instructor << ", Schedule: " << schedule << endl;
    }
};

int main() {
    Student s1("Ali", "S123", "Street 1", "123456", "ali@mail.com", 5, 3.7, 2023);
    Professor p1("Dr. Ahmed", "P456", "Street 2", "654321", "ahmed@mail.com", "CS", 3, 50000);
    Staff st1("Sarah", "ST789", "Street 3", "987654", "sarah@mail.com", "Admin", "Manager", 40000);
    
    Person* people[3] = { &s1, &p1, &st1 };
    
    for (int i = 0; i < 3; i++) {
        people[i]->displayInfo();
    }
    
    Course c1("CS101", "Programming Fundamentals", 3, "Dr. Ahmed", "MWF 10:00-11:30");
    c1.displayCourse();
    c1.registerStudent(&s1);
    c1.calculateGrades();
    
    return 0;
}
