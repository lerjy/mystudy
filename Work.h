#pragma once
#include <iostream>
#include <string>
using namespace std;

class Work
{
public:
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	//职工的编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_Dpid;
};