#include<iostream>
#include<string>
#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int deptId) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;
}
void Manager::showInfo() {
	cout << "职工编号：" << this->id << "\t职工姓名：" << this->name << "\t职工岗位：" << this->getDeptName() << "\t岗位职责：完成老板交代的任务" << endl;
}
string Manager::getDeptName() {
	return string("经理");
}