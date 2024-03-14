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
			wm.add_worker();
			system("pause");
			system("cls");
			break;
		case 2: //显示职工信息
			wm.show_workerInfo();
			system("pause");
			system("cls");
			break;
		case 3: //删除指定职工
			wm.del_worker();
			system("pause");
			system("cls");
			break;
		case 4://修改职工
			wm.mod_worker();
			system("pause");
			system("cls");
			break;
		case 5://查找职工
			wm.find_worker();
			system("pause");
			system("cls");
			break;
		case 6://按照编号排序
			wm.sort_worker();
			system("pause");
			system("cls");
			break;
		case 7://清空文档
			wm.clean_file();
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}
	return 0;
}