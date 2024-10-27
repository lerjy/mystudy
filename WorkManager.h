#pragma once
#include <iostream>
#include "Work.h"
#include <fstream>

#define FileName "empFile.txt"

using namespace std;

class WorkManager
{
public:
	//构造函数
	WorkManager();
	//展示菜单
	void ShowMenu();
	//退出系统
	void exitSystem();

	//添加职工的方法
	void Addemp();

	//保存文件
	void save();

	//读取文件
	//统计文件中的职工人数
	int get_empNum();
	//初始化职工
	void init_emp();

	//记录职工人数
	int m_EmpNum;

	//显示职工信息
	void showEmp();

	//判断职工是否存在
	int empIsexit(int id);

	//删除职工信息
	void delEmp();

	//修改职工信息
	void ModyEmp();

	//查找职工信息
	void LookEmp();

	//按职工编号排序
	void SortEmp();

	//清空职工信息
	void RmEmp();

	//职工数组指针
	Work ** m_EmpArray;

	//析构函数
	~WorkManager();


	//判断文件是否为空的成员属性
	bool m_isEmpty;
};
