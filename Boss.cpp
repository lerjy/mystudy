#include "Boss.h"

Boss::Boss(int id, string name, int dpid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Dpid = dpid;
}


//显示个人信息
void Boss::showInfo()
{
	cout << "职工的编号：" << this->m_Id
		<< "\t职工的姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：" << this->getWork() << endl;
}

//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}

string Boss::getWork()
{
	return string("负责干活");
}
