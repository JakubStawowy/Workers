#include "List.h"
#include "Worker.h"
#include "Trainee.h"
#include "FullTimeWorker.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
#include <fstream>
using namespace std;
List::List() {

	first = 0;

}
List::~List()
{
}
void List::add(string x, string y, int z, int w) {

	char p;

	cout << "Choose type: " << endl << "1) Worker" << endl << "2) Trainee" << endl;

	p = _getch();
	cout << endl << "Name:";
	cin >> x;
	cout << endl;
	cout << "Lastname: ";
	cin >> y;
	cout << endl;
	cout << "Age: ";
	cin >> w;
	cout << endl;

	switch (p) {

	case '1': {	

		Worker* now = new FullTimeWorker(x,y,w,z);

		if (first == 0) {

			first = now;

		}
		else {

			Worker* bufor = first;

			while (bufor->n) {

				bufor = bufor->n;

			}

			bufor->n = now;
			now->n = 0;
		}

		break;

	}

	case '2': {

		Worker* now = new Trainee(x,y,w,z);
		
		if (first == 0) {

			first = now;

		}
		else {

			Worker* bufor = first;

			while (bufor->n) {

				bufor = bufor->n;

			}

			bufor->n = now;
			now->n = 0;

		}

		break;

	}
	}

	return;
}
int List::add_from_file() {

	int number=0;
	fstream File;
	File.open("data.txt", ios::in);

	if (File.fail()) {

		cout << "Failed to open file" << endl << "Create new file \"data\" in File Explorer";
		exit(0);

	}

	string gett[7];
	int  g;
	double l,f;
	int i = 0;

	while (File.good()) {

		getline(File, gett[0]);//numer

		if (File.fail()) {

			break;

		}

		string sw = gett[0];
		istringstream isf(sw);
		isf >> g;
		getline(File, gett[1]);//imie
		getline(File, gett[2]);//nazwisko
		getline(File, gett[3]);//wiek

		if (File.fail()) {

			break;

		}

		string st = gett[3];
		istringstream is(st);
		is >> i;

		getline(File, gett[4]);//stawka

		if (File.fail()) {

			break;

		}
		string str = gett[4];
		istringstream iss(str);
		iss >> f;
		getline(File, gett[5]);//Zus

		if (File.fail()) {

			break;

		}

		string stg = gett[5];
		istringstream isg(stg);
		isg >> l;
		getline(File, gett[6]);//typ

		Worker* now = new Worker(gett[1],gett[2],i,g,f,gett[6],l);//pracownik(string imie, string nazwisko, int wiek, int nr, int stawka, string typ)
		
		if (first == 0) {

			first = now;

		}
		else {

			Worker* bufor = first;

			while (bufor->n) {

				bufor = bufor->n;

			}

			bufor->n = now;
			now->n = 0;

		}

		number = g;

	}
	File.close();
	return number;

}
void List::choose() {
	cout << endl << "1) Search with number" << endl << "2)Search with name" << endl;
	char g;
	g = _getch();

	switch (g) {

	case '1': {

		cout << "Enter the number of worker ";
		int numb;
		cin >> numb;

		Worker* p = first;

		while (p->n) {

			if (p->find(numb, "")) break;

			p = p->n;

		}

		if (p->find(numb, "")) {

			cout << *p << endl << "---------------------------------------------------------" << endl;
			p->rise();

		}
		else cout << "There's no such number";
		
		return;
	}
	case '2': {
		cout << "Enter the name of worker: ";
		string name;
		cin >> name;

		Worker* p = first;

		while (p->n) {

			if (p->find(0,name)) break;
			p = p->n;

		}

		if (p->find(0, name)) {

			cout << endl;
			cout << *p << endl << "---------------------------------------------------------" << endl;
			p->rise();

		}
		else cout << "There's no such name" << endl;

		return;
	
	}
	default:
		cout << "There's no such function" << endl;
		return;

	}
}
int List::delete_chos() {

	cout << endl << "1) Delete with number" << endl << "2)Delete with name" << endl;
	char g;
	g = _getch();

	switch (g) {

	case '1': {

		cout << "Enter the number of worker: ";
		int numb;
		cin >> numb;

		Worker* p = first;
		
		if (!p) {

			return 0;

		}

		if (numb == 1) {

			Worker* bufor = first;
			first = bufor->n;

			while (bufor) {

				//bufor->nr--;
				bufor->dinc_nr();
				bufor = bufor->n;

			}
		}

		if (numb >= 2) {

			Worker* bufor = first;

			int j = 1;

			while (bufor) {

				if ((j + 1) == numb) break;

				bufor = bufor->n;
				j++;

			}
			if (bufor->n->n == 0)
				bufor->n = 0;
			else {

				bufor->n = bufor->n->n;

				while (bufor->n) {

					bufor->n->dinc_nr();
					bufor = bufor->n;

				}
			}
		}

		Worker::counter--;
		return 1;
	}
	case '2': {
		cout << "Enter the name of worker: ";
		string name;
		cin >> name;

		Worker* p = first;

		if (!p) {

			return 0;

		}

		else
			while (p->n) {

				if (p->find(0,name)) break;
				p = p->n;

			}

		if (p->find(0, name)) {

			int numb = p->get_nr();

			if (numb == 1) {

				Worker* bufor = first;
				first = bufor->n;

				while (bufor) {

					bufor->dinc_nr();
					bufor = bufor->n;

				}
			}

			if (numb >= 2) {

				Worker* bufor = first;
				int j = 1;

				while (bufor) {

					if ((j + 1) == numb) break;
					bufor = bufor->n;
					j++;

				}

				if (bufor->n->n == 0)
					bufor->n = 0;
				else {

					bufor->n = bufor->n->n;

					while (bufor->n) {

						bufor->n->dinc_nr();
						bufor = bufor->n;

					}
				}
			}
			return 1;
		}
		else cout << "There's no such name" << endl;
		Worker::counter--;
		return 0;
	}
	}
	return 1;
}
ostream& operator <<(ostream& stream, const List& w) {

	ofstream savedata("data.txt");

	Worker* p = w.first;

	while (p) {

		stream << *p;
		stream << endl << "--------------------------------------------------------------------------" << endl;
		savedata << *p;
		p = p->n;

	}
	savedata.close();
	stream << endl;
	return stream;

}