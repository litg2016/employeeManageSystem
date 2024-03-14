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