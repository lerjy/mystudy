#include "Manager.h"


Manager::Manager(int id, string name, int dpid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Dpid = dpid;
}
//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ���ı�ţ�" << this->m_Id
		<< "\tְ����������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��" << this->getWork() << endl;

}

//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}

//��ȡ��λְ��
string Manager::getWork()
{
	return string("����Ա��");
}