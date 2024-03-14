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
	cout << "��ӭ�´�ʹ�ã������˳�" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::show_menu() {

	cout << "*****************************************************" << endl;
	cout << "***************��ӭʹ��ְ������ϵͳ******************" << endl;
	cout << "***************    0.�˳�����ϵͳ  ******************" << endl;
	cout << "***************    1.����ְ����Ϣ  ******************" << endl;
	cout << "***************    2.��ʾְ����Ϣ  ******************" << endl;
	cout << "***************    3.ɾ����ְְ��  ******************" << endl;
	cout << "***************    4.�޸�ְ����Ϣ  ******************" << endl;
	cout << "***************    5.����ְ����Ϣ  ******************" << endl;
	cout << "***************    6.���ձ������  ******************" << endl;
	cout << "***************    7.��������ĵ�  ******************" << endl;
	cout << "*****************************************************" << endl;
	cout << endl;
}


//���ְ��
void WorkerManager::add_worker() {

	cout << "���������ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum <= 0) {
		cout << "�������ݲ��Ϸ�" << endl;
	}
	int newSize = this->num + addNum;
	Worker** newSpace = new Worker * [newSize];  //����ָ��
	if (this->p_Woker != NULL) {
		for (int i = 0; i < this->num; i++)
			newSpace[i] = this->p_Woker[i];
	}
	//���������
	for (int i = 0; i < addNum; i++) {
		int id, deptId;
		string name;
		cout << "������� " << i + 1 << "��ְ���ı��" << endl;
		cin >> id;
		cout << "������� " << i + 1 << "��ְ��������" << endl;
		cin >> name;
		cout << "��ѡ���ְ����λ��\n1.��ְͨ��\n2.����\n3.�ܲ�\n" << endl;
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
	cout << "�ɹ����" << addNum << "����ְ��" << endl;
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
		cout << "�ļ�Ϊ��" << endl;
	}
	int num = this->num;
	for (int i = 0; i < num; i++) {
		Worker* w = this->p_Woker[i];
		w->showInfo();
	}
	cout << "��ʾ���" << endl;
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
		cout << "�ļ�������" << endl;
		return;
	}
	cout << "������Ҫɾ��ְ����ţ�" << endl;
	int id;
	cin >> id;
	int index = is_exist(id);
	if (index == -1) { cout << "ְ�������ڣ��޷�ɾ��" << endl; return; }
	for (int i = index; i < num - 1; i++) {
		this->p_Woker[i] = this->p_Woker[i + 1];
	}
	this->num--;
	cout << "ɾ���ɹ���" << endl;
	save();
}

void WorkerManager::mod_worker() {
	if (this->isFileEmpty) {
		cout << "�ļ�Ϊ�գ�" << endl;
		return;
	}
	cout << "�������޸�ְ����ţ�" << endl;
	int id;
	cin >> id;
	int index = this->is_exist(id);
	if (index == -1) {
		cout << "Ҫ�޸�ְ����Ų�����" << endl;
		return;
	}
	delete this->p_Woker[index];
	Worker* w = NULL;
	cout << "���ҵ���ְ����������ְ���±�ţ�" << endl;
	int newId, newDeptId;
	string newName;
	cin >> newId;
	cout << "������ְ�������֣�" << endl;
	cin >> newName;
	cout << "�������λ��\n1.��ְͨ��\n2.����\n3.�ܲ�\n" << endl;
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
	cout << "�޸ĳɹ�" << endl;
	save();
}

void WorkerManager::find_worker() {
	if (this->isFileEmpty) {
		cout << "�ļ�Ϊ��" << endl;
	}
	cout << "��������ҷ�ʽ��\n1.���ձ�Ų��� \n 2.������������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "���������ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = this->is_exist(id);
		if (index == -1) { cout << "���޴���" << endl; }
		else {
			cout << "���ҳɹ�����Ϣ����:" << endl;
			this->p_Woker[index]->showInfo();
		}
	}
	else if (select == 2) {
		string name;
		cout << "����������" << endl;
		cin >> name;
		bool flag = false;
		for (int i = 0; i < this->num; i++) {
			if (this->p_Woker[i]->name == name) {
				cout << "���ҳɹ�����Ϣ���£�" << endl;
				flag = true;
				this->p_Woker[i]->showInfo();
			}
		}
		if (flag == false) { cout << "���޴���" << endl; }
	}
	else {
		cout << "���ҷ�ʽ��������" << endl;
	}
}

void WorkerManager::sort_worker() {
	if (this->isFileEmpty) {
		cout << "�ļ�Ϊ��,�޷�����" << endl;
		return;
	}
	cout << "��ѡ������ʽ��\n1.��ְ���������\n2.��ְ����Ž���" << endl;
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
	cout << "����ɹ�" << endl;
	this->save();
	this->show_workerInfo();
}
void WorkerManager::clean_file() {
	cout << "ȷ����գ�1.ȷ�� 2.����" << endl;
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