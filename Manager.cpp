#include "Manager.h"


Manager::Manager(int id, string name, int dpid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Dpid = dpid;
}
//显示个人信息
void Manager::showInfo()
{
	cout << "职工的编号：" << this->m_Id
		<< "\t职工的姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：" << this->getWork() << endl;

}

//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}

//获取岗位职责
string Manager::getWork()
{
	return string("服务员工");
}