#pragma once
#include <iostream>
#include <string>
#include "Work.h"
using namespace std;

class Employee :public Work
{
public:
	Employee(int id,string name,int dpid);
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();

	//��ȡ��λְ��
	string getWork();
};
