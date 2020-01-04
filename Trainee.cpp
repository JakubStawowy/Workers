#include "Trainee.h"
Trainee::Trainee(string name, string lastname, int age, int nr) {
	type = "Trainee";
	salary = 500;
	zus = salary * 0.45;
	this->name = name;
	this->lastname = lastname;
	this->age = age;
	this->nr = nr;
}
