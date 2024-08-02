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
			cout << "�����������������룺";
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "����˺�" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			man->cleanFile();
			break;
		case 0:
			man->savefile();
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "û�д�ѡ��" << endl;
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
			cout << "�����������������룺";
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "�鿴�ҵ�ԤԼ" << endl;
			stu->showMyorder();
			break;
		case 3:
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllorder();
			break;
		case 4:
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "û�д�ѡ��" << endl;
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
			cout << "�����������������룺";
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllorder();
			break;
		case 2:
			cout << "���ԤԼ" << endl;
			tea->valiOrder();
			break;
		case 0:
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "û�д�ѡ��" << endl;
			break;
		}
	}
}


void existsystem()
{
	cout << "\t\tȷ���˳�ϵͳ?" << endl;
	cout << "\t\t  0--ȷ��" << endl;
	cout << "\t\t  1--����" << endl;
	cout << "\t\t���������ѡ��";
	int choice;
	cin >> choice;
	while (choice < 0 || choice>1 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "\t\t�����������������룺";
		cin >> choice;
	}
	if (choice == 0)
	{
		cout << "\t\t|  �˳��ɹ�" << endl;
		cout << "\t\t|��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}
	else 
	{
		cout << "\t\t���سɹ�!" << endl;
		system("cls");
		return;
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڻ��ļ��޷���" << endl;
		ifs.close();
		return;
	}

	string id;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�����������û�����" << endl;
	cin >> name;

	cout << "�������������룺" << endl;
	pwd = secretword();
	cout << endl;
	//ѧ�������֤
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
				cout << "ѧ�������֤ͨ������¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	//��ʦ�����֤
	else if (type == 2)
	{
		string fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ�����֤ͨ������¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	//����Ա�����֤
	else if (type == 3)
	{

		string fname;
		string fpwd;
		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "����Ա�����֤ͨ������¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "�����֤δͨ������¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}


int main()
{

	int select = 0;

	while (1) 
	{
		cout << "===============================��ӭ��������ԤԼϵͳ===============================" << endl;
		cout << endl << "=====������������ݣ�" << endl;
		cout << "\t\t ---------------------------------------------------\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        1-ѧ  ��                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        2-��  ʦ                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        3-����Ա                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t|                        0-��  ��                   |\n";
		cout << "\t\t|                                                   |\n";
		cout << "\t\t ---------------------------------------------------\n";
		cout << "\t\t|����������ѡ��";

		cin >> select;
		while (select < 0 || select>3 || cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "�����������������룺";
			cin >> select;
		}
		
		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			existsystem(); break;
		}
		system("pause");
		system("cls");
	}
}