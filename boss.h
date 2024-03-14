#pragma once
#include<iostream>
#include "worker.h"
using namespace std; 


class Boss :public Worker {
public:
	Boss(int, string, int);
	void showInfo();
	string getDeptName();
};