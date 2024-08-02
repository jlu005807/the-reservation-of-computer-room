#include"globalFile.h"
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<conio.h>
#include<ctype.h>
using namespace std;


string secretword() {
	string key = "";
	unsigned char c;
	int i = 0;
	while ((c = _getch()) != '\r') {
		if (i < 20 && isprint(c)) {
			key += c;
			i++;
			putchar('*');
		}
		else if (i > 0 && c == '\b') {
			i--;
			key.pop_back();
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	return key;
}

void managerMenu(Identity*& manager)
{
	while (1)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		while (cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "输入有误，请重新输入：";
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "添加账号" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "查看账号" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "查看机房" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			man->cleanFile();
			break;
		case 0:
			man->savefile();
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "没有此选项" << endl;
			break;
		}

	}
}

void studentMenu(Identity*& student)
{
	while (1)
	{
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		while (cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "输入有误，请重新输入：";
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "申请预约" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "查看我的预约" << endl;
			stu->showMyorder();
			break;
		case 3:
			cout << "查看所有预约" << endl;
			stu->showAllorder();
			break;
		case 4:
			cout << "取消预约" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "没有此选项" << endl;
			break;
		}
	}
}


void teacherMenu(Identity* &teacher)
{
	while (1)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		while (cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "输入有误，请重新输入：";
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "查看所有预约" << endl;
			tea->showAllorder();
			break;
		case 2:
			cout << "审核预约" << endl;
			tea->valiOrder();
			break;
		case 0:
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "没有此选项" << endl;
			break;
		}
	}
}


void existsystem()
{
	cout << "\t\t确定退出系统?" << endl;
	cout << "\t\t  0--确定" << endl;
	cout << "\t\t  1--返回" << endl;
	cout << "\t\t请输入你的选择：";
	int choice;
	cin >> choice;
	while (choice < 0 || choice>1 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "\t\t输入有误，请重新输入：";
		cin >> choice;
	}
	if (choice == 0)
	{
		cout << "\t\t|  退出成功" << endl;
		cout << "\t\t|欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}
	else 
	{
		cout << "\t\t返回成功!" << endl;
		system("cls");
		return;
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在或文件无法打开" << endl;
		ifs.close();
		return;
	}

	string id;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入您的用户名：" << endl;
	cin >> name;

	cout << "请输入您的密码：" << endl;
	pwd = secretword();
	cout << endl;
	//学生身份验证
	if (type == 1)
	{
		string fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			/*cout << fid << " " << fname << " " << fpwd << endl;
			system("pause");*/
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生身份验证通过，登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	//教师身份验证
	else if (type == 2)
	{
		string fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师身份验证通过，登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	//管理员身份验证
	else if (type == 3)
	{

		string fname;
		string fpwd;
		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "管理员身份验证通过，登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "身份验证未通过，登录失败！" << endl;
	system("pause");
	system("cls");
}


int main()
{

	int select = 0;

	while (1) 
	{
		cout << "===============================欢迎来到机房预约系统===============================" << endl;
		cout << endl << "=====请输入您的身份：" << endl;
		cout << "\t\t ---------------------------------------------------\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        1-学  生                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        2-老  师                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        3-管理员                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        0-退  出                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t ---------------------------------------------------\n";
		cout << "\t\t|请输入您的选择：";

		cin >> select;
		while (select < 0 || select>3 || cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "输入有误，请重新输入：";
			cin >> select;
		}
		
		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			existsystem(); break;
		}
		system("pause");
		system("cls");
	}
}