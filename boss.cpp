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
	cout << "ְ����ţ�" << this->id << "\tְ��������" << this->name << "\tְ����λ��" << this->getDeptName() << "\t��λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptName() {
	return string("�ܲ�");
}