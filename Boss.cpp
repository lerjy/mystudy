#include "Boss.h"

Boss::Boss(int id, string name, int dpid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Dpid = dpid;
}


//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ���ı�ţ�" << this->m_Id
		<< "\tְ����������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��" << this->getWork() << endl;
}

//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}

string Boss::getWork()
{
	return string("����ɻ�");
}
