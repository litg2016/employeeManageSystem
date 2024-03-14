#include "workerManager.h"
#include<iostream>
#include<fstream>
#define FILENAME "file.txt"
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		this->num = 0;
		this->p_Woker = NULL;
		this->isFileEmpty = true;
	}
	else {
		int id, deptId;
		string name;
		int num = 0;
		while (ifs >> id && ifs >> name && ifs >> deptId) {
			num++;
		}
		this->num = num;
		if (num == 0) { this->p_Woker = NULL; return; }
		this->isFileEmpty = false;
		this->p_Woker = new Worker * [num];
		int index = 0;
		ifs.clear();
		ifs.seekg(0, ios::beg);
		//ifs >> id;
		while (ifs >> id && ifs >> name && ifs >> deptId)
		{
			Worker* worker = NULL;
			switch ( deptId)
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
			this->p_Woker[index++] = worker;
		}




	}
	
}


WorkerManager::~WorkerManager() {
	if (this->p_Woker != NULL) {
		for (int i = 0; i < num; i++) {
			if (this->p_Woker[i]) {
				delete this->p_Woker[i];
			}
		}
		delete[] this->p_Woker;
		this->num = 0;
		this->p_Woker = NULL;
	}
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

void WorkerManager::show_workerInfo() {
	if (this->isFileEmpty) {
		cout << "文件为空" << endl;
	}
	int num = this->num;
	for (int i = 0; i < num; i++) {
		Worker* w = this->p_Woker[i];
		w->showInfo();
	}
	cout << "显示完毕" << endl;
}

int WorkerManager::is_exist(int id) {
	int index = -1;
	for (int i = 0; i < this->num; i++) {
		Worker* w = this->p_Woker[i];
		if (w->id == id) {
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::del_worker() {
	if (this->isFileEmpty) {
		cout << "文件不存在" << endl;
		return;
	}
	cout << "请输入要删除职工编号：" << endl;
	int id;
	cin >> id;
	int index = is_exist(id);
	if (index == -1) { cout << "职工不存在，无法删除" << endl; return; }
	for (int i = index; i < num - 1; i++) {
		this->p_Woker[i] = this->p_Woker[i + 1];
	}
	this->num--;
	cout << "删除成功！" << endl;
	save();
}

void WorkerManager::mod_worker() {
	if (this->isFileEmpty) {
		cout << "文件为空！" << endl;
		return;
	}
	cout << "请输入修改职工编号：" << endl;
	int id;
	cin >> id;
	int index = this->is_exist(id);
	if (index == -1) {
		cout << "要修改职工编号不存在" << endl;
		return;
	}
	delete this->p_Woker[index];
	Worker* w = NULL;
	cout << "查找到该职工，请输入职工新编号：" << endl;
	int newId, newDeptId;
	string newName;
	cin >> newId;
	cout << "请输入职工新名字：" << endl;
	cin >> newName;
	cout << "请输入岗位：\n1.普通职工\n2.经理\n3.总裁\n" << endl;
	cin >> newDeptId;
	switch (newDeptId) {
	case 1:
		w = new Employee(newId, newName, newDeptId);
		break;
	case 2:
		w = new Manager(newId, newName, newDeptId);
		break;
	case 3:
		w = new Boss(newId, newName, newDeptId);
		break;
	default:
		break;

	}
	this->p_Woker[index] = w;
	cout << "修改成功" << endl;
	save();
}

void WorkerManager::find_worker() {
	if (this->isFileEmpty) {
		cout << "文件为空" << endl;
	}
	cout << "请输入查找方式：\n1.按照编号查找 \n 2.按照姓名查找" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "请输入查找职工编号：" << endl;
		int id;
		cin >> id;
		int index = this->is_exist(id);
		if (index == -1) { cout << "查无此人" << endl; }
		else {
			cout << "查找成功，信息如下:" << endl;
			this->p_Woker[index]->showInfo();
		}
	}
	else if (select == 2) {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		bool flag = false;
		for (int i = 0; i < this->num; i++) {
			if (this->p_Woker[i]->name == name) {
				cout << "查找成功，信息如下：" << endl;
				flag = true;
				this->p_Woker[i]->showInfo();
			}
		}
		if (flag == false) { cout << "查无此人" << endl; }
	}
	else {
		cout << "查找方式输入有误" << endl;
	}
}

void WorkerManager::sort_worker() {
	if (this->isFileEmpty) {
		cout << "文件为空,无法排序" << endl;
		return;
	}
	cout << "请选择排序方式：\n1.按职工编号升序\n2.按职工编号降序" << endl;
	int select;
	cin >> select;
	for (int i = 0; i < this->num; i++) {
		int index = i;
		for (int j = i + 1; j < num; j++) {
			if (select == 1) {
				if (this->p_Woker[index]->id > this->p_Woker[j]->id)
					index = j;
			}
			else {
				if (this->p_Woker[index]->id < this->p_Woker[j]->id)
					index = j;
			}
		}
		if (i != index) {
			Worker* temp = this->p_Woker[i];
			this->p_Woker[i] = this->p_Woker[index];
			this->p_Woker[index] = temp;
		}
	}
	cout << "排序成功" << endl;
	this->save();
	this->show_workerInfo();
}
void WorkerManager::clean_file() {
	cout << "确定清空？1.确定 2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select != 1) return;
	ofstream ofs(FILENAME, ios::trunc);
	ofs.close();
	if (this->p_Woker != NULL) {
		for (int i = 0; i < num; i++) {
			if (this->p_Woker[i]) {
				delete this->p_Woker[i];
			}
		}
		delete[] this->p_Woker;
		this->num = 0;
		this->p_Woker = NULL;
	}
}