#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    float gpa;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void writeToFile(ofstream& outFile) {
        outFile << id << " " << name << " " << gpa << endl;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }

    void readFromStream(ifstream& inFile) {
        inFile >> id;
        inFile.ignore(); 
        getline(inFile, name, ' ');
        inFile >> gpa;
    }
};

int main() {
    Student s;

    ofstream outFile("students.txt", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "Enter data for 5 students:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        s.input();
        s.writeToFile(outFile);
    }
    outFile.close();

    ofstream appendFile("students.txt", ios::app);
    if (!appendFile) {
        cerr << "Error opening file for appending!" << endl;
        return 1;
    }

    cout << "\nEnter data for 1 additional student:\n";
    s.input();
    s.writeToFile(appendFile);
    appendFile.close();
    
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nAll Student Records from file:\n";
    while (inFile >> s.id >> s.name >> s.gpa) {
        s.display();
    }

    inFile.close();
    return 0;
}
