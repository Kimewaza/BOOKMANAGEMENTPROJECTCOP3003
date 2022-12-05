#include "Book.h"

using namespace std;

void Book::createBook() {
	clear_screen();
	int bookID = 0; //new counter
	cout << "\n\n\t\t\t\t\t\tADDING BOOK: " << "\n\n";
	cout << "NAME OF BOOK: ";
	getline(cin, bookName);
	cout << "NAME OF AUTHOR: ";
	getline(cin, authorName);

	ifstream bid("bookdatabase.dat"); //Basically just gets the number inside the .datfile and adds one to it and then in the next part it will increment and put the right 
	//book number. 
	while (getline(bid, line)) {
		bookID++;
		//cout << bookID; read/counts what the current "id" is at an adds 1 to the one thats inside the file
	}
	bid.close();

	ofstream file;
	file.open("bookdatabase.dat", ios::app); //Previous version used a txt file but it conflicted with a lot of the code and just never editted/added properly 
	//and after searching it online a .dat was better apparently.
	//bookDetail = to_string(bookID) + ", BOOK NAME: " + bookName + ", AUTHOR NAME: " + authorName;
	bookDetail = to_string(bookID) + "\t\t\t" + bookName + "\t\t\t" + authorName;
	file << bookDetail << endl;
	file.close();
	cout << "Book Successfully Created" << endl << "BOOK ID:\t\tBOOK NAME:\t\t\tAUTHOR:\n" << bookDetail << endl;

}
void Book::displayBooks() {
	//system("cls");
	clear_screen();
	cout << "\n\nDISPLAYING ALL BOOKS\n\nBOOK ID : \t\tBOOK NAME : \t\t\tAUTHOR:\n";
	ifstream outfile("bookdatabase.dat");
	string x;
	while (getline(outfile, x)) {
		cout << x << endl;
	}
	outfile.close();
}
void Book::modifyBook() {
	//system("cls");
	clear_screen();
	string input1;
	displayBooks();
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
			cout << "Book Details:\nEDITING...\n" << tempstring << endl;
			cout << "BOOK TITLE: ";
			getline(cin, nBookName);
			cout << "AUTHOR: ";
			getline(cin, nAuthorName);
			tempstring = input1 + "\t\t\t" + nBookName + "\t\t\t" + nAuthorName;
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
		cout << "Invalid ID" << input1 << endl;
	}
}
void Book::delete_line() {
	string line_num; //changed from int to string since it needs to read the file to find the number in string
	cout << "Enter the ID of the book to Delete: ";
	cin >> line_num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// open file in read mode or in mode
	ifstream is("bookdatabase.dat");
	// open file in write mode or out mode
	ofstream ofs;
	ofs.open("temp.dat", ios::app);
	//loop to read single characters from entire file
	char x;
	int line_no = 0;
	while (is.get(x)) {
		// if a newline character
		if (x == '\n')
			line_no++;
		//specifies what characters to keep(keeps all characters outside of the line to be deleted)
		if (to_string(line_no) != line_num)
			ofs << x;
	}
	// closing output file
	ofs.close();
	// closing input file
	is.close();
	// remove the original file
	remove("bookdatabase.dat");
	// rename the file
	rename("temp.dat", "bookdatabase.dat");
}
void clear_screen() {
	string(10, '\n');
}
