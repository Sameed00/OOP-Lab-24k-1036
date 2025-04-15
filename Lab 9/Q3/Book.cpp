#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
Book::Book(){}
Book::Book(string t, string a,string n):title(t),author(a),ISBN(n){}

string Book::getAuthor(){return author;}
string Book::getISBN(){return ISBN;}
string Book::getTitle(){return title;}
