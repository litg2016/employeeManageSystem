#include<iostream>
#include"employee.h"

using namespace std;

Employee::Employee(int id, string name, int deptId) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;

}
void Employee::showInfo() {
	cout << "职工编号：" << this->id << "\t职工姓名：" << this->name << "\t职工岗位：" << this->getDeptName() << "\t岗位职责：完成经理交代的任务" << endl;
}
string Employee::getDeptName() {
	return string("员工");
}