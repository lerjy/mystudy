#pragma once
#include "WorkManager.h"
#include "Work.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

//using namespace std;


//构造函数
WorkManager::WorkManager()
{
	this->m_isEmpty = false;

	//判断文件存在性
	ifstream ifs;
	ifs.open(FileName, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但数据为空
	char ch;
	if ((ifs >> ch).eof())
	{
		//cout << "你在找什么？这里空空如也" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	//文件存在并有数据
	this->m_EmpNum = this->get_empNum();
	//cout << "现职工人数为：" << this->m_EmpNum << endl;

	//初始化职工数组
	this->m_EmpArray = new Work * [this->m_EmpNum];
	this->init_emp();
	//for (int i = 0;i < this->m_EmpNum;i++)
	//{
	//	this->m_EmpArray[i]->showInfo();
	//}
}
//添加职工函数
void WorkManager::Addemp()
{
	cout << "请输入添加的职工人数：" << endl;
	int addnum = 0;//保存输入的添加职工人数
	cin >> addnum;
	//cout << "addnum = " << addnum << endl;
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;

		//开辟新空间
		Work** newSpace = new Work * [newSize];

		//将原来的数据拷贝
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0;i < addnum;i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dpid;//部门编号

			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个职工的部门" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dpid;
			Work* work = NULL;
			switch (dpid)
			{
			case 1:
				work = new Employee(id, name, dpid);
				break;
			case 2:
				work = new Manager(id, name, dpid);
				break;
			case 3:
				work = new Boss(id, name, dpid);
				break;
			}
			newSpace[this->m_EmpNum + i] = work;
		}
		//释放原有的空间
		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;

		//保存数据到文件
		this->save();

		//更改文件为空的标志
		this->m_isEmpty = false;

		//释放堆区空间
		//for (int i = 0;i < this->m_EmpNum;i++)
		//{
		//	delete this->m_EmpArray[i];
		//}

		cout << "成功添加" << addnum << "位职工" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键继续
	system("pause");
	system("cls");
}
//保存数据到文件
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FileName, ios::out);

	//将数据写入到文件
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<< " "
			<< this->m_EmpArray[i]->m_Name<< " "
			<< this->m_EmpArray[i]->m_Dpid << endl;
	}

	ofs.close();
}

//读取文件中的职工人数
int WorkManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FileName, ios::in);
	int id;
	string name;
	int dpid;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dpid)
	{
		//统计人数	
		num++;
	}
	ifs.close();
	return num;
}
//初始化职工到堆区
void WorkManager::init_emp()
{
	ifstream ifs;
	ifs.open(FileName, ios::in);
	int id;
	string name;
	int dpid;

	int num = 0;
	Work* work = NULL;

	while (ifs >> id && ifs >> name && ifs >> dpid)
	{
		if (dpid == 1)
		{
			this->m_EmpArray[num] = new Employee(id, name, dpid);
		}
		else if (dpid == 2)
		{
			this->m_EmpArray[num] = new Manager(id, name, dpid);
		}
		else
		{
			this->m_EmpArray[num] = new Boss(id, name, dpid);
		}	
		num++;
	}
	ifs.close();
}
//	//显示职工信息
void WorkManager::showEmp()
{
	if (this->m_isEmpty)
	{
		cout << "文件为空或不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "在职工人数为：" << this->m_EmpNum << endl;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int WorkManager::empIsexit(int id)
{
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//cout << "该职工存在，编号为：" << this->m_EmpArray[i]->m_Id << endl;
			return i;
		}
	}
	cout << "该职工记录不存在！" << endl;
	return -1;
}

//删除职工信息
void WorkManager::delEmp()
{
	if (this->m_isEmpty)
	{
		cout << "文件为空或不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Inid;
	int index;
	cout << "请输入删除的职工编号：" << endl;

	//堆区更新职工信息
	cin >> index;
	Inid = this->empIsexit(index);
	if (Inid + 1)
	{
		//Work** work = NULL;
		//cout << Inid << endl;
		//cout << this->m_EmpNum << endl;
		delete this->m_EmpArray[Inid];
		for (int i = Inid;i < (this->m_EmpNum - 1);i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;

		//更新文件中职工信息
		this->save();

		cout << "编号为" << index << "的职工删除成功！" << endl;
	}
	//
	system("pause");
	system("cls");
}

//修改职工信息
void WorkManager::ModyEmp()
{
	if (this->m_isEmpty)
	{
		cout << "文件记录为空或不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Inid;
	int index;
	cout << "请输入修改的职工编号：" << endl;

	//堆区删除职工信息
	cin >> index;
	Inid = this->empIsexit(index);
	if (Inid + 1)
	{
		int id;
		string name;
		int dpid;
		cout << "请输入该职工编号：" << endl;
		cin >> id;
		cout << "请输入该职工姓名：" << endl;
		cin >> name;
		cout << "请输入该职工部门编号：" << endl;
		cin >> dpid;
		Work* work = NULL;
		switch (dpid)
		{
		case 1:
			work = new Employee(id, name, dpid);
			break;
		case 2:
			work = new Manager(id, name, dpid);
			break;
		case 3:
			work = new Boss(id, name, dpid);
			break;
		}
		//堆区删除该职工信息
		delete this->m_EmpArray[Inid];
		this->m_EmpArray[Inid] = work;
		//更新文件中职工信息
		this->save();

		cout << "编号为" << index << "的职工修改成功！" << endl;
		this->m_EmpArray[Inid]->showInfo();
	}
	//
	system("pause");
	system("cls");
}

//查找职工信息
void WorkManager::LookEmp()
{
	if (this->m_isEmpty)
	{
		cout << "文件记录为空或不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Inid;
	int index;
	cout << "请输入查找的职工编号：" << endl;

	cin >> index;
	Inid = this->empIsexit(index);
	if (Inid + 1)
	{
		this->m_EmpArray[Inid]->showInfo();
	}
	system("pause");
	system("cls");
}
//按职工编号排序
void WorkManager::SortEmp()
{
	if (this->m_isEmpty)
	{
		cout << "文件记录为空或不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int SortIndex;
	cout << "请选择排序方式：" << endl;
	cout << "1、按职工编号升序排列" << endl;
	cout << "2、按职工编号降序排列" << endl;
	Loop:cin >> SortIndex;
	//升序排列
	if (SortIndex == 1)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			for (int j = 0;j < this->m_EmpNum - i - 1;j++)
			{
				if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
				{
					Work* temp = NULL;
					temp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = temp;
				}
			}
		}
	}
	//降序排列
	else if (SortIndex == 2)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			for (int j = 0;j < this->m_EmpNum - i - 1;j++)
			{
				if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
				{
					Work* temp = NULL;
					temp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = temp;
				}
			}
		}
	}
	else
	{
		cout << "输入有误！请重新输入：" << endl;
		goto Loop;
	}
	//更新文件内容
	this->save();

	cout << "职工信息排序成功！" << endl;
	system("pause");
	system("cls");
}
//清空职工信息
void WorkManager::RmEmp()
{
	//判断文件是否为空或记录为空
	if (this->m_isEmpty)
	{
		cout << "文件记录为空或不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Cur;
	cout << "请确认删除所有信息：" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	cin >> Cur;
	if (Cur == 1)
	{
		//删除原文件，重新创建空文件
		ofstream ofs;
		ofs.open(FileName, ios::trunc);
		ofs.close();

		//释放堆区空间
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			delete this->m_EmpArray[i];
		}
		this->m_EmpNum = 0;

		////释放数组指针，注意析构函数也有一次释放
		//if (this->m_EmpArray != NULL)
		//{
		//	delete[] this->m_EmpArray;
		//	this->m_EmpArray = NULL;
		//}
	}
	else
	{
		cout << "操作已取消" << endl;
		system("pause");
		system("cls");
		return;
	}
	this->m_isEmpty = true;
	cout << "所有职工信息已清空！" << endl;
	char ch;
	cout << "按任意键返回主菜单(按0退出系统)" << endl;
	cin >> ch;
	if (ch == '0')
	{
		this->exitSystem();
	}
	system("pause");
	system("cls");
}

//展示菜单
void WorkManager::ShowMenu()
{
	cout << "*--------------------------*" << endl;
	cout << "---欢迎使用职工管理系统！---" << endl;
	cout << "----- 0、退出管理系统 ------" << endl;
	cout << "----- 1、添加职工信息 ------" << endl;
	cout << "----- 2、显示职工信息 ------" << endl;
	cout << "----- 3、删除职工信息 ------" << endl;
	cout << "----- 4、修改职工信息 ------" << endl;
	cout << "----- 5、查找职工信息 ------" << endl;
	cout << "----- 6、按照编号排序 ------" << endl;
	cout << "----- 7、清空所有信息 ------" << endl;
	cout << "*--------------------------*" << endl;
	cout << endl;
	return;
}
//退出系统
void WorkManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}