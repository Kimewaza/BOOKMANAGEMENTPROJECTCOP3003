/*
This project mainly aims to get used to file managing and the potential and limiations of file handling in C++
This program is able to add, modify, and view the books database. Each book is given its id number automatically on creation while the person just adds/modiffies
the name and author of the book.
*/
/*
RESOURCES USED:
https://www.w3schools.com/cpp/cpp_files.asp
https://www.geeksforgeeks.org/file-handling-c-classes/
https://www.edureka.co/blog/file-handling-in-cpp/
https://stackoverflow.com/questions
https://www.geeksforgeeks.org/getline-string-c/
https://www.w3schools.com/cpp/cpp_booleans.asp
https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
*/

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class book {
private:
	string bookName, authorName, bookDetail, line;
	//int counter = 0; Setting it inside a private area made it so if books started with numbers would skip a couple counters so moving it to a public area fixed the issue
public:
	void createBook() {
		system("cls");
		int counter = 0; //new counter
		cout << "\n\n\t\t\t\t\t\tADDING BOOK: " << "\n\n";
		cout << "NAME OF BOOK: ";
		getline(cin, bookName);
		cout << "NAME OF AUTHOR: ";
		getline(cin, authorName);

		ifstream counting("bookdatabase.dat"); //Basically just gets the number inside the .datfile and adds one to it and then in the next part it will increment and put the right 
		//book number. 
		while (getline(counting, line)) {
			counter++;
		}
		counting.close();

		ofstream file;
		file.open("bookdatabase.dat", ios::app); //Previous version used a txt file but it conflicted with a lot of the code and just never editted/added properly 
		//and after searching it online a .dat was better apparently.
		bookDetail = to_string(counter) + ", BOOK NAME: " + bookName + ", AUTHOR NAME: " + authorName;
		file << bookDetail << endl;
		file.close();
		cout << "Book Successfully Created" << endl << bookDetail << endl;

	}
	void displayBooks() {
		system("cls");
		cout << "\n\n\t\t\t\t\t\tDISPLAYING ALL BOOKS"<<"\n\n";
		ifstream outfile("bookdatabase.dat");
		string x;
		while (getline(outfile, x)) {
			cout << x << endl;
		}
	}
	void modifyBook() {
		system("cls");
		string input1;
		cout << "Book Number: ";
		cin >> input1;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores any white space inputs that might be inside the inputs
		bool tempbool = false;
		ifstream file("bookdatabase.dat");
		ofstream temp;
		temp.open("temp.dat", ios::app);

		if (!file || !temp) {
			cout << "Error" << endl;
			return;
		}
		string tempstring;
		while (getline(file, tempstring)) {
			size_t found = tempstring.find(input1);
			if (found != string::npos) {
				string nBookName, nAuthorName;
				cout << "Book Details:\nEDITING...\n"<<"BOOK ID: \n" << tempstring << endl;
				cout << "BOOK TITLE: ";
				getline(cin, nBookName);
				cout << "AUTHOR: ";
				getline(cin, nAuthorName);
				tempstring = input1 + ", BOOK NAME: " + nBookName + ", AUTHOR NAME:  " + nAuthorName;
				tempbool = true;
			}
			temp << tempstring << endl;

		}
		file.close();
		temp.close();

		if (tempbool) {
			if (remove("bookdatabase.dat") != 0);
			perror("Error");
			if (rename("temp.dat", "bookdatabase.dat")) {
				perror("Error");
				return;
			}
			cout << "Successfully Modified" << endl;


		}
		else {
			cout << "Invalid ID" << input1<< endl;
		}
		

	}
	
};

book bk; // had to set it globally or else some of the inputs and functions wouldn't work in other places

void mainMenu() {
	system("cls");
	cout << "\t\t\t\tPLEASE INPUT AN OPTION AVAILABLE ON THE SCREEN" << "\n\n";
	cout << "\t\t\t\t\t1. ADD BOOK: " << endl;
	cout << "\t\t\t\t\t2. MODIFY PREEXISTING BOOK: " << endl;
	cout << "\t\t\t\t\t3. DISPLAY BOOKS:  " << endl;
	cout << "\t\t\t\t\t0. EXIT " << endl;
	cout << "YOU CHOICE: ";
	int input = 0;
	cin >> input;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (input != 0 && input <= 3) {
		switch (input) {
		case 1:
			bk.createBook();
			break;
		case 2:
			bk.modifyBook();
			break;
		case 3:
			bk.displayBooks();
			break;
		}
	}
	else if (input > 3) {
		cout << "INVALID INPUT. \nPlease pick a valid input" << endl;
		mainMenu();
	}
	else {
		exit(0);
	}
}

int main() {
	cout << "\n\n\t\t\t\t\t\tBOOK MANAGEMENT SYSTEM\n\n\t\t\t\tBY: JOHN NGUYEN, AARON MARKOWITZ, and ALEXANDER FATJO";
	_getch();
	system("cls");
	string input1;
	while (true) {
		mainMenu();
		cout << "Continue? ('Y' or 'N')" << endl;
		cout << "CHOICE: ";
		cin >> input1;
		if ((input1 != "Y") && (input1 != "y") && (input1 != "Yes") && (input1 != "yes") && (input1 != "YES")) {
			break;
		}
	}
	return 0;

}



