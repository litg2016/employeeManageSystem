#include<iostream>
#include"workerManager.h"
using namespace std;


int main() {
	WorkerManager wm;


	while (true) {
		wm.show_menu();
		cout << "���������ѡ��" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice) {
		case 0: //�˳�ϵͳ
			wm.exit_system();
			break;
		case 1: //����ְ����Ϣ
			wm.add_worker();
			system("pause");
			system("cls");
			break;
		case 2: //��ʾְ����Ϣ
			wm.show_workerInfo();
			system("pause");
			system("cls");
			break;
		case 3: //ɾ��ָ��ְ��
			wm.del_worker();
			system("pause");
			system("cls");
			break;
		case 4:
			wm.mod_worker();
			system("pause");
			system("cls");
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}
	return 0;
}