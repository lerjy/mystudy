#pragma once
#include <iostream>
#include "Work.h"
#include <fstream>

#define FileName "empFile.txt"

using namespace std;

class WorkManager
{
public:
	//���캯��
	WorkManager();
	//չʾ�˵�
	void ShowMenu();
	//�˳�ϵͳ
	void exitSystem();

	//���ְ���ķ���
	void Addemp();

	//�����ļ�
	void save();

	//��ȡ�ļ�
	//ͳ���ļ��е�ְ������
	int get_empNum();
	//��ʼ��ְ��
	void init_emp();

	//��¼ְ������
	int m_EmpNum;

	//��ʾְ����Ϣ
	void showEmp();

	//�ж�ְ���Ƿ����
	int empIsexit(int id);

	//ɾ��ְ����Ϣ
	void delEmp();

	//�޸�ְ����Ϣ
	void ModyEmp();

	//����ְ����Ϣ
	void LookEmp();

	//��ְ���������
	void SortEmp();

	//���ְ����Ϣ
	void RmEmp();

	//ְ������ָ��
	Work ** m_EmpArray;

	//��������
	~WorkManager();


	//�ж��ļ��Ƿ�Ϊ�յĳ�Ա����
	bool m_isEmpty;
};
