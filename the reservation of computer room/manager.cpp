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
		cout << "�ļ������ڻ��ļ���ȡʧ��!" << endl;
	
	}
	else
	{
		while (ifs >> com.m_Comid && ifs >> com.m_MaxNum)
		{
			vCom.push_back(com);
		}
		ifs.close();
		cout << "����������Ϊ��" << vCom.size() << endl;
	}
	initVector();
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        1-����˺�                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        2-�鿴�˺�                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        3-�鿴����                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        4-���ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        0-ע����¼                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
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
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "       1.ѧ��" << endl;
	cout << "       2.��ʦ" << endl;
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
		cout << "\t\t�����������������룺";
		cin >> choice;
	}

	if (choice == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ������������룺";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errortip = "ְ�����ظ������������룺";
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
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;
	if (choice == 1) {
		vStu.push_back(Student(id, name, pwd));
	}
	else
	{
		vTea.push_back(Teacher(id, name, pwd));
	}
	cout << "��ӳɹ�" << endl;
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
		cout << "�ļ������ڻ��ļ���ȡʧ��!" << endl;
		return;
	}
	else
	{
		Student s;
		while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_password)
		{
			vStu.push_back(s);
		}
		cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
		ifs.close();
	}

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڻ��ļ���ȡʧ��!" << endl;
		return;
	}
	else
	{
		Teacher s;
		while (ifs >> s.m_empid && ifs >> s.m_name && ifs >> s.m_password)
		{
			vTea.push_back(s);
		}
		cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
		ifs.close();
	}
	return;
}


void Manager::printStu(Student& s)
{
	cout << "ѧ�ţ�" << s.m_id << "   ������" << s.m_name << "   ���룺" << s.m_password << endl;
	return;
}
void Manager::printTea(Teacher& t)

{
	cout << "ְ���ţ�" << t.m_empid << "   ������" << t.m_name << "   ���룺" << t.m_password << endl;
	return;
}

void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1.�鿴���е�ѧ�� " << endl;
	cout << "2.�鿴���еĽ�ʦ " << endl;
	int choice = 0;
	cin >> choice;
	while (choice < 1 || choice>2 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "\t\t�����������������룺";
		cin >> choice;
	}
	if (choice == 1)
	{
		cout << "���е�ѧ����Ϣ���£�" << endl;
		if (vStu.size() == 0) {
			cout << "����ѧ����Ϣ" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < vStu.size(); i++)
		{
			printStu(vStu[i]);
		}
		cout << "���е���Ϣչʾ���" << endl;

	}
	else
	{
		cout << "���еĽ�ʦ��Ϣ���£�" << endl;
		if (vTea.size() == 0) {
			cout << "���޽�ʦ��Ϣ" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < vTea.size(); i++)
		{
			printTea(vTea[i]);
		}
		cout << "���е���Ϣչʾ���" << endl;
	}
	system("pause");
	system("cls");
	return;
}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << "������ţ�" << vCom[i].m_Comid << "   �������������" << vCom[i].m_MaxNum << endl;
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

	cout << "ԤԼ��Ϣ������ϣ�" << endl;
	system("pause");
	system("cls");
	return;
}