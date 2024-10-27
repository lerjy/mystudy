#pragma once
#include "WorkManager.h"
#include "Work.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

//using namespace std;


//���캯��
WorkManager::WorkManager()
{
	this->m_isEmpty = false;

	//�ж��ļ�������
	ifstream ifs;
	ifs.open(FileName, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڵ�����Ϊ��
	char ch;
	if ((ifs >> ch).eof())
	{
		//cout << "������ʲô������տ���Ҳ" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڲ�������
	this->m_EmpNum = this->get_empNum();
	//cout << "��ְ������Ϊ��" << this->m_EmpNum << endl;

	//��ʼ��ְ������
	this->m_EmpArray = new Work * [this->m_EmpNum];
	this->init_emp();
	//for (int i = 0;i < this->m_EmpNum;i++)
	//{
	//	this->m_EmpArray[i]->showInfo();
	//}
}
//���ְ������
void WorkManager::Addemp()
{
	cout << "��������ӵ�ְ��������" << endl;
	int addnum = 0;//������������ְ������
	cin >> addnum;
	//cout << "addnum = " << addnum << endl;
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;

		//�����¿ռ�
		Work** newSpace = new Work * [newSize];

		//��ԭ�������ݿ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0;i < addnum;i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dpid;//���ű��

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "��ְ���Ĳ���" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;

		//�������ݵ��ļ�
		this->save();

		//�����ļ�Ϊ�յı�־
		this->m_isEmpty = false;

		//�ͷŶ����ռ�
		//for (int i = 0;i < this->m_EmpNum;i++)
		//{
		//	delete this->m_EmpArray[i];
		//}

		cout << "�ɹ����" << addnum << "λְ��" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}
//�������ݵ��ļ�
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FileName, ios::out);

	//������д�뵽�ļ�
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<< " "
			<< this->m_EmpArray[i]->m_Name<< " "
			<< this->m_EmpArray[i]->m_Dpid << endl;
	}

	ofs.close();
}

//��ȡ�ļ��е�ְ������
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
		//ͳ������	
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ��ְ��������
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
//	//��ʾְ����Ϣ
void WorkManager::showEmp()
{
	if (this->m_isEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ְ������Ϊ��" << this->m_EmpNum << endl;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkManager::empIsexit(int id)
{
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//cout << "��ְ�����ڣ����Ϊ��" << this->m_EmpArray[i]->m_Id << endl;
			return i;
		}
	}
	cout << "��ְ����¼�����ڣ�" << endl;
	return -1;
}

//ɾ��ְ����Ϣ
void WorkManager::delEmp()
{
	if (this->m_isEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Inid;
	int index;
	cout << "������ɾ����ְ����ţ�" << endl;

	//��������ְ����Ϣ
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

		//�����ļ���ְ����Ϣ
		this->save();

		cout << "���Ϊ" << index << "��ְ��ɾ���ɹ���" << endl;
	}
	//
	system("pause");
	system("cls");
}

//�޸�ְ����Ϣ
void WorkManager::ModyEmp()
{
	if (this->m_isEmpty)
	{
		cout << "�ļ���¼Ϊ�ջ򲻴��ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Inid;
	int index;
	cout << "�������޸ĵ�ְ����ţ�" << endl;

	//����ɾ��ְ����Ϣ
	cin >> index;
	Inid = this->empIsexit(index);
	if (Inid + 1)
	{
		int id;
		string name;
		int dpid;
		cout << "�������ְ����ţ�" << endl;
		cin >> id;
		cout << "�������ְ��������" << endl;
		cin >> name;
		cout << "�������ְ�����ű�ţ�" << endl;
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
		//����ɾ����ְ����Ϣ
		delete this->m_EmpArray[Inid];
		this->m_EmpArray[Inid] = work;
		//�����ļ���ְ����Ϣ
		this->save();

		cout << "���Ϊ" << index << "��ְ���޸ĳɹ���" << endl;
		this->m_EmpArray[Inid]->showInfo();
	}
	//
	system("pause");
	system("cls");
}

//����ְ����Ϣ
void WorkManager::LookEmp()
{
	if (this->m_isEmpty)
	{
		cout << "�ļ���¼Ϊ�ջ򲻴��ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Inid;
	int index;
	cout << "��������ҵ�ְ����ţ�" << endl;

	cin >> index;
	Inid = this->empIsexit(index);
	if (Inid + 1)
	{
		this->m_EmpArray[Inid]->showInfo();
	}
	system("pause");
	system("cls");
}
//��ְ���������
void WorkManager::SortEmp()
{
	if (this->m_isEmpty)
	{
		cout << "�ļ���¼Ϊ�ջ򲻴��ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int SortIndex;
	cout << "��ѡ������ʽ��" << endl;
	cout << "1����ְ�������������" << endl;
	cout << "2����ְ����Ž�������" << endl;
	Loop:cin >> SortIndex;
	//��������
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
	//��������
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
		cout << "�����������������룺" << endl;
		goto Loop;
	}
	//�����ļ�����
	this->save();

	cout << "ְ����Ϣ����ɹ���" << endl;
	system("pause");
	system("cls");
}
//���ְ����Ϣ
void WorkManager::RmEmp()
{
	//�ж��ļ��Ƿ�Ϊ�ջ��¼Ϊ��
	if (this->m_isEmpty)
	{
		cout << "�ļ���¼Ϊ�ջ򲻴��ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int Cur;
	cout << "��ȷ��ɾ��������Ϣ��" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	cin >> Cur;
	if (Cur == 1)
	{
		//ɾ��ԭ�ļ������´������ļ�
		ofstream ofs;
		ofs.open(FileName, ios::trunc);
		ofs.close();

		//�ͷŶ����ռ�
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			delete this->m_EmpArray[i];
		}
		this->m_EmpNum = 0;

		////�ͷ�����ָ�룬ע����������Ҳ��һ���ͷ�
		//if (this->m_EmpArray != NULL)
		//{
		//	delete[] this->m_EmpArray;
		//	this->m_EmpArray = NULL;
		//}
	}
	else
	{
		cout << "������ȡ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	this->m_isEmpty = true;
	cout << "����ְ����Ϣ����գ�" << endl;
	char ch;
	cout << "��������������˵�(��0�˳�ϵͳ)" << endl;
	cin >> ch;
	if (ch == '0')
	{
		this->exitSystem();
	}
	system("pause");
	system("cls");
}

//չʾ�˵�
void WorkManager::ShowMenu()
{
	cout << "*--------------------------*" << endl;
	cout << "---��ӭʹ��ְ������ϵͳ��---" << endl;
	cout << "----- 0���˳�����ϵͳ ------" << endl;
	cout << "----- 1�����ְ����Ϣ ------" << endl;
	cout << "----- 2����ʾְ����Ϣ ------" << endl;
	cout << "----- 3��ɾ��ְ����Ϣ ------" << endl;
	cout << "----- 4���޸�ְ����Ϣ ------" << endl;
	cout << "----- 5������ְ����Ϣ ------" << endl;
	cout << "----- 6�����ձ������ ------" << endl;
	cout << "----- 7�����������Ϣ ------" << endl;
	cout << "*--------------------------*" << endl;
	cout << endl;
	return;
}
//�˳�ϵͳ
void WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
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