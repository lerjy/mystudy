#include "Employee.h"
using namespace std;

//构造函数
Employee::Employee(int id, string name, int dpid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Dpid = id;
}

//显示个人信息
void Employee::showInfo() 
{
	cout << "职工的编号：" << this->m_Id
		<< "\t职工的姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：" << this->getWork() << endl;
}

//获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
}
string Employee::getWork()
{
	return string("负责玩乐");
}
