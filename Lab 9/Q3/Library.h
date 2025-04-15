#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include <iostream>
using namespace std;

class Library{
	protected:
		Book books[10];
		
	public:
		Library();
		void addBook();
		void removeBook();
		void searchBook();
};

#endif