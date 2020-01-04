#include "FullTimeWorker.h"
FullTimeWorker::FullTimeWorker(string name, string lastname, int age, int nr) {
	type = "Full Time Worker";
	salary = 2600;
	zus = salary * 0.45;
	this->name = name;
	this->lastname = lastname;
	this->age = age;
	this->nr = nr;
}
