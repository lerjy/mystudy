#pragma once
#include <iostream>
#include <string>
#include "Work.h"
using namespace std;

class Employee :public Work
{
public:
	Employee(int id,string name,int dpid);
	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();

	//获取岗位职责
	string getWork();
};
