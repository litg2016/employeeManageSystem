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
	cout << "ְ����ţ�" << this->id << "\tְ��������" << this->name << "\tְ����λ��" << this->getDeptName() << "\t��λְ������ϰ彻��������" << endl;
}
string Manager::getDeptName() {
	return string("����");
}