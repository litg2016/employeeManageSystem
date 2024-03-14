#include<iostream>
#include"workerManager.h"
using namespace std;


int main() {
	WorkerManager wm;


	while (true) {
		wm.show_menu();
		cout << "请输入你的选择：" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice) {
		case 0: //退出系统
			wm.exit_system();
			break;
		case 1: //增加职工信息

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}