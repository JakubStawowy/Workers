#pragma once
#ifndef PelnyEtat_H
#define PelnyEtat_H
#include "Worker.h"
class FullTimeWorker :public Worker {
public:
	FullTimeWorker(string name, string lastname, int age, int nr);
};
#endif


