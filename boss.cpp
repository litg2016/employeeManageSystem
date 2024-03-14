#include<iostream>
#include<string>
#include"boss.h"
using namespace std;

Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;
}
void Boss::showInfo() {
	cout << "职工编号：" << this->id << "\t职工姓名：" << this->name << "\t职工岗位：" << this->getDeptName() << "\t岗位职责：管理公司所有事物" << endl;
}
string Boss::getDeptName() {
	return string("总裁");
}