#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

class WorkerManager {
private:
	int num;
	Worker** p_Woker;
public:
	void show_menu();  //展示菜单函数
	WorkerManager();
	~WorkerManager();
	void exit_system();
	void add_worker();
	void save();
	
};