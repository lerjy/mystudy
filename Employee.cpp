#include "Employee.h"
using namespace std;

//���캯��
Employee::Employee(int id, string name, int dpid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Dpid = id;
}

//��ʾ������Ϣ
void Employee::showInfo() 
{
	cout << "ְ���ı�ţ�" << this->m_Id
		<< "\tְ����������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��" << this->getWork() << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}
string Employee::getWork()
{
	return string("��������");
}
