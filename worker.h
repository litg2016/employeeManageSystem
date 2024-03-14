#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象类
class Worker {
public:
	int id;
	string name;
	int deptId;

	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
};