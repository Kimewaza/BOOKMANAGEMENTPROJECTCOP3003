#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <limits>

using namespace std;

class Book {
private:
	string bookName, authorName, bookDetail, line;

public:
	void createBook();

	void displayBooks();

	void modifyBook();

	void delete_line();

};

void clear_screen();

#endif
