#include"Manager.h"
Manager::Manager()
{

}

Manager::Manager(string name, string password)
{
	this->m_name = name;
	this->m_password = password;

	ifstream ifs(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	if (!ifs.is_open())
	{
		cout << "文件不存在或文件读取失败!" << endl;
	
	}
	else
	{
		while (ifs >> com.m_Comid && ifs >> com.m_MaxNum)
		{
			vCom.push_back(com);
		}
		ifs.close();
		cout << "机房的数量为：" << vCom.size() << endl;
	}
	initVector();
}

void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        1-添加账号                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        2-查看账号                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        3-查看机房                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        4-清空预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        0-注销登录                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "请选择您的操作：";
	return;
}

bool Manager::checkRepeat(string id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "       1.学生" << endl;
	cout << "       2.老师" << endl;
	string filename;
	string tip;
	string errortip;

	int choice = 0;
	cin >> choice;
	while (choice < 1 || choice>2 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "\t\t输入有误，请重新输入：";
		cin >> choice;
	}

	if (choice == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入：";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工号：";
		errortip = "职工号重复，请重新输入：";
	}


	string id;
	string name;
	string pwd;

	cout << tip;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, choice);
			if (ret)
			{
				cout << errortip << endl;
			}
			else
			{
				break;
			}
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	if (choice == 1) {
		vStu.push_back(Student(id, name, pwd));
	}
	else
	{
		vTea.push_back(Teacher(id, name, pwd));
	}
	cout << "添加成功" << endl;
	savefile();
	system("pause");
	system("cls");
	return;
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在或文件读取失败!" << endl;
		return;
	}
	else
	{
		Student s;
		while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_password)
		{
			vStu.push_back(s);
		}
		cout << "当前学生数量为：" << vStu.size() << endl;
		ifs.close();
	}

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在或文件读取失败!" << endl;
		return;
	}
	else
	{
		Teacher s;
		while (ifs >> s.m_empid && ifs >> s.m_name && ifs >> s.m_password)
		{
			vTea.push_back(s);
		}
		cout << "当前教师数量为：" << vTea.size() << endl;
		ifs.close();
	}
	return;
}


void Manager::printStu(Student& s)
{
	cout << "学号：" << s.m_id << "   姓名：" << s.m_name << "   密码：" << s.m_password << endl;
	return;
}
void Manager::printTea(Teacher& t)

{
	cout << "职工号：" << t.m_empid << "   姓名：" << t.m_name << "   密码：" << t.m_password << endl;
	return;
}

void Manager::showPerson()
{
	cout << "请选择查看的内容：" << endl;
	cout << "1.查看所有的学生 " << endl;
	cout << "2.查看所有的教师 " << endl;
	int choice = 0;
	cin >> choice;
	while (choice < 1 || choice>2 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "\t\t输入有误，请重新输入：";
		cin >> choice;
	}
	if (choice == 1)
	{
		cout << "所有的学生信息如下：" << endl;
		if (vStu.size() == 0) {
			cout << "暂无学生信息" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < vStu.size(); i++)
		{
			printStu(vStu[i]);
		}
		cout << "所有的信息展示完毕" << endl;

	}
	else
	{
		cout << "所有的教师信息如下：" << endl;
		if (vTea.size() == 0) {
			cout << "暂无教师信息" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < vTea.size(); i++)
		{
			printTea(vTea[i]);
		}
		cout << "所有的信息展示完毕" << endl;
	}
	system("pause");
	system("cls");
	return;
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << "机房编号：" << vCom[i].m_Comid << "   机房最大容量：" << vCom[i].m_MaxNum << endl;
	}
	system("pause");
	system("cls");
	return;
}


void Manager::savefile()
{
	ofstream ofs(STUDENT_FILE, ios::out || ios::trunc);
	for (int i = 0; i < vStu.size(); i++)
	{
		ofs << vStu[i].m_id << " " << vStu[i].m_name << " " << vStu[i].m_password << endl;
	}
	ofs.close();

	ofs.open(TEACHER_FILE, ios::out || ios::trunc);
	for (int i = 0; i < vTea.size(); i++)
	{
		ofs << vTea[i].m_empid << " " << vTea[i].m_name << " " << vTea[i].m_password << endl;
	}
	ofs.close();

}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "预约信息清理完毕！" << endl;
	system("pause");
	system("cls");
	return;
}