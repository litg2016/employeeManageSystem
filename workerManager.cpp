#include "workerManager.h"
#include<iostream>
#include<fstream>
#define FILENAME "file.txt"
WorkerManager::WorkerManager() {
	this->num = 0;
	this->p_Woker = NULL;
}


WorkerManager::~WorkerManager() {

}
void WorkerManager::exit_system() {
	cout << "欢迎下次使用，即将退出" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::show_menu() {

	cout << "*****************************************************" << endl;
	cout << "***************欢迎使用职工管理系统******************" << endl;
	cout << "***************    0.退出管理系统  ******************" << endl;
	cout << "***************    1.增加职工信息  ******************" << endl;
	cout << "***************    2.显示职工信息  ******************" << endl;
	cout << "***************    3.删除离职职工  ******************" << endl;
	cout << "***************    4.修改职工信息  ******************" << endl;
	cout << "***************    5.查找职工信息  ******************" << endl;
	cout << "***************    6.按照编号排序  ******************" << endl;
	cout << "***************    7.清空所有文档  ******************" << endl;
	cout << "*****************************************************" << endl;
	cout << endl;
}


//添加职工
void WorkerManager::add_worker() {

	cout << "请输入添加职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum <= 0) {
		cout << "输入数据不合法" << endl;
	}
	int newSize = this->num + addNum;
	Worker** newSpace = new Worker * [newSize];  //数组指针
	if (this->p_Woker != NULL) {
		for (int i = 0; i < this->num; i++)
			newSpace[i] = this->p_Woker[i];
	}
	//添加新数据
	for (int i = 0; i < addNum; i++) {
		int id, deptId;
		string name;
		cout << "请输入第 " << i + 1 << "个职工的编号" << endl;
		cin >> id;
		cout << "请输入第 " << i + 1 << "个职工的姓名" << endl;
		cin >> name;
		cout << "请选择该职工岗位：\n1.普通职工\n2.经理\n3.总裁\n" << endl;
		cin >> deptId;
		Worker* worker = NULL;
		switch (deptId)
		{
		case 1:
			worker = new Employee(id, name, deptId);
			break;
		case 2:
			worker = new Manager(id, name, deptId);
			break;
		case 3:
			worker = new Boss(id, name, deptId);
			break;
		default:
			break;
		}
		newSpace[this->num + i] = worker;
	}
	delete[] this->p_Woker;
	this->p_Woker = newSpace;
	this->num = newSize;
	cout << "成功添加" << addNum << "名新职工" << endl;
	save();
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->num; i++) {
		ofs << this->p_Woker[i]->id << "\t" << this->p_Woker[i]->name << "\t" << this->p_Woker[i]->deptId << endl;
	}
	ofs.close();
}