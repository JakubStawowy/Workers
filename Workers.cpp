#include "Worker.h"
#include "List.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
	int w = 0;
	char c;
	string x, y;
	List* base = new List;
	int number = 1;
	number +=base->add_from_file();
	cout << *base;
	for (;;) {//Menu glowne

		cout << "Choose function:" << endl << "1) Add" << endl << "2) Exit" << endl << "3) Find/Edit" << endl << "4) Delete" <<endl;

		c = _getch();

		switch (c) {

		case '1': {

			base->add(x, y, number, w);
			number++;
			cout << *base;
			break;

		}
		case '2': {

			base->~List();
			exit(0);

		}
		case '3': {

			base->choose();
			cout << *base;
			break;

		}
		case '4': {

			if (!base->delete_chos()) {

				cout << "Negative. There's no any worker left!" << endl;
				break;

			}
			number--;
			cout << *base;
			break;

		}
		default: {

			cout << "There's no such option" << endl;
			break;

		}
		}
	}
	return 0;
}
