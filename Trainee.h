#pragma once
#ifndef staz_H
#define staz_H
#include "Worker.h"
class Trainee :public Worker {
public:
	Trainee(string name, string lastname, int age, int nr);
};
#endif // !staz_H


