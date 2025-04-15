#include "Book.h"
#include "Library.h"
#include <iostream>
using namespace std;

int main(){
	Book b1("Harry Potter","JK R","21235");
	cout<<b1.getAuthor()<<endl<<b1.getISBN()<<endl<<b1.getTitle()<<endl;
	Library l1;
	l1.addBook();
	l1.removeBook();
	l1.searchBook();
}