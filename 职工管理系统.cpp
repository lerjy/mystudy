#include "WorkManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
	////���Զ�
	//Boss em1(1,"����",3);
	//em1.showInfo();
	//exit(0);

	WorkManager wm;
	char select;
	while (1)
	{
		wm.ShowMenu();
		cout << "����������ѡ��";
		cin >> select;
		// select = '0' �˳�ϵͳ
		switch (select)
		{
		case '0'://�˳�ϵͳ
			wm.exitSystem();
		case '1'://�����Ϣ
			wm.Addemp();
			break;
		case '2'://��ʾ��Ϣ
			wm.showEmp();
			break;
		case '3'://ɾ����Ϣ
		{
			//wm.empIsexit(100);
			wm.delEmp();
			break;
		}
		//case�������̫����Ҫ��{}������
		case '4'://�޸���Ϣ
			wm.ModyEmp();
			break;
		case '5'://������Ϣ
			wm.LookEmp();
			break;
		case '6'://������Ϣ
			wm.SortEmp();
			break;
		case '7'://�����Ϣ
			wm.RmEmp();
			break;
		default:
			system("cls");
			break;
		}
	}
}