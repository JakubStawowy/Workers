#pragma once
#ifndef Class_H
#define Class_H
#include <iostream>
#include <string>
using namespace std;
class Worker {
public:
	friend ostream& operator<<(ostream& stream, const Worker& p);
	Worker* n;
	Worker();
	~Worker() {
	};
	Worker(string imie, string nazwisko, int wiek, int nr,double stawka,string typ,double zus);
	bool find(int,string);
	void rise();
	void dinc_nr();
	int get_nr();
	static int counter;
protected:
	int nr;
	string name;
	string lastname;
	string type;
	int age;
	double salary;
	double zus;
};

#endif // !Class_H