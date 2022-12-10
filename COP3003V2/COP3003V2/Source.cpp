/*
This project mainly aims to get used to file managing and the potential and limitations of file handling in C++
This program is able to add, modify, and view the books database. Each book is given its id number automatically on creation while the person just adds/modiffies
the name and author of the book.
RESOURCES USED:
https://www.w3schools.com/cpp/cpp_files.asp
https://www.geeksforgeeks.org/file-handling-c-classes/
https://www.edureka.co/blog/file-handling-in-cpp/
https://stackoverflow.com/questions
https://www.geeksforgeeks.org/getline-string-c/
https://www.w3schools.com/cpp/cpp_booleans.asp
https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
https://www.geeksforgeeks.org/program-delete-line-given-line-number-file/
*/

#include "Book.h"

Book bk; // had to set it globally or else some of the inputs and functions wouldn't work in other places


	void mainMenu() {
		system("cls");
		cout << "\nPLEASE INPUT AN OPTION AVAILABLE ON THE SCREEN \n\t[1]-ADD BOOK\n\t"
			"[2]-MODIFY PREEXISTING BOOK\n\t[3]-DISPLAY BOOKS\n\t[4]-Delete Book\n\t[0]-EXIT\n\n\t\tCHOICE [ ]\b\b";
		int input = 0;
		cin >> input;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input != 0 && input <= 4) {
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
			case 4:
				/*
				int line_num;
				cout << "Enter the ID of the book to Delete: ";     //Removed the input into the function itself  and removed the parameters for it
				cin >> line_num;
				*/
				bk.delete_line();
				break;
			}
		}

		else if (input > 4) {
			cout << "INVALID INPUT. \nPlease pick a valid input" << endl;
			mainMenu();
		}
		else {
			exit(0);
		}
	}


int main() {
	cout << "\n\n\tBOOK MANAGEMENT SYSTEM\n\t\tBY: JOHN NGUYEN, AARON MARKOWITZ, and ALEXANDER FATJO";
	_getch(); //conio.h file allows for this. Basically holds the screen until something is inputted
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



