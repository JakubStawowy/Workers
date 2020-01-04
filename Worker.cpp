#include "Worker.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
#include <fstream>
using namespace std;
int Worker::counter = 0;
Worker::Worker() {
	name = "";
	lastname = "";
	age = 0;
	nr = 0;
	type = "";
	salary = 0;
	counter++;
}
Worker::Worker(string name, string lastname, int age, int nr,double salary,string type,double zus) {

	this->name = name;
	this->lastname = lastname;
	this->age = age;
	this->salary = salary;
	this->nr = nr;
	this->type = type;
	this->zus = zus;
	counter++;
}
bool Worker::find(int nr,string name) {

	if (this->nr == nr || this->name == name)
		return true;
	else return false;

}
void Worker::rise() {
	char q;
	cout << endl << "1)Edit" << endl << "...)Exit" << endl;
	q = _getch();

	switch (q) {

	case '1': {
		cout << endl << "Enter value of the rise: ";
		double val;
		cin >> val;
		salary += val;
		zus = salary * 0.45;
	}
	default: break;
	}
	
}
void Worker::dinc_nr()
{
	nr--;
}
int Worker::get_nr()
{
	return nr;
}
ostream& operator <<(ostream& stream, const Worker& p) {
	
	stream << p.nr << endl  << p.name << endl  << p.lastname << endl  << p.age << endl << p.salary <<endl<<p.zus<< endl << p.type << endl;
	
	return stream;
}
