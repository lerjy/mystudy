#include "WorkManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
	////测试段
	//Boss em1(1,"张三",3);
	//em1.showInfo();
	//exit(0);

	WorkManager wm;
	char select;
	while (1)
	{
		wm.ShowMenu();
		cout << "请输入您的选择：";
		cin >> select;
		// select = '0' 退出系统
		switch (select)
		{
		case '0'://退出系统
			wm.exitSystem();
		case '1'://添加信息
			wm.Addemp();
			break;
		case '2'://显示信息
			wm.showEmp();
			break;
		case '3'://删除信息
		{
			//wm.empIsexit(100);
			wm.delEmp();
			break;
		}
		//case下面代码太多需要用{}括起来
		case '4'://修改信息
			wm.ModyEmp();
			break;
		case '5'://查找信息
			wm.LookEmp();
			break;
		case '6'://排序信息
			wm.SortEmp();
			break;
		case '7'://清空信息
			wm.RmEmp();
			break;
		default:
			system("cls");
			break;
		}
	}
}