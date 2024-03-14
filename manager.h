#pragma once
#include "worker.h"
class Manager :public Worker {
public:
	Manager(int, string, int);
	virtual void showInfo();
	virtual string getDeptName();
};