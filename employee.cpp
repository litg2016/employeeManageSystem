#include<iostream>
#include"employee.h"

using namespace std;

Employee::Employee(int id, string name, int deptId) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;

}
void Employee::showInfo() {
	cout << "ְ����ţ�" << this->id << "\tְ��������" << this->name << "\tְ����λ��" << this->getDeptName() << "\t��λְ����ɾ�����������" << endl;
}
string Employee::getDeptName() {
	return string("Ա��");
}