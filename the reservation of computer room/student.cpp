#include"Student.h"

Student::Student()
{

}

Student::Student(string id, string name, string password)
{
	this->m_id = id;
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
	}
}

void Student::operMenu()
{
	cout << "��ӭѧ����" << this->m_name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        1-����ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        2-�鿴�ҵ�ԤԼ               |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        3-�鿴����ԤԼ               |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        4-ȡ��ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        0-ע����¼                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
	return;
}

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "��ѡ������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ 2.�ܶ� 3.���� 4.���� 5.���� 0.����" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	cin >> date;
	while (date<0||date>5||cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "�����������������룺";
		cin >> date;
	}
	if (date == 0)
	{
		cout << "���سɹ�!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ѡ������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.���磨8��00 - 12��00��   2.���磨14��00 - 18:00�� 0.����" << endl;
	
	cin >> interval;
	while (interval < 0 || interval>2 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "�����������������룺";
		cin >> interval;
	}
	if (interval == 0)
	{
		cout << "���سɹ�!" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	
	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_Comid << "�Ż�������Ϊ��" << vCom[i].m_MaxNum << endl;
	}
	cout << "----------------------------------------------------------" << endl;

	cin >> room;
	while (room < 1 || room>vCom.size() || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "�����������������룺";
		cin >> room;
	}
	cout << endl;
	cout << "ԤԼ�ɹ��������......" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " interval:" << interval << " stuId:" << this->m_id << " stuName:" << this->m_name << " roomId:" << room << " status:"/*ԤԼ״̬*/ << 1 << " " << endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "ԤԼ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		/*cout << of.m_orderDate[i]["stuId"] << endl;*/
		if (of.m_orderDate[i]["stuId"] == this->m_id)
		{
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
			cout << "    ʱ��Σ�" ;
			if (of.m_orderDate[i]["interval"] == "1")cout << "����";
			else cout << "����";
			cout << "   ������ţ�" << of.m_orderDate[i]["roomId"];
			string status = "   ԤԼ״̬��";
			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "�����.....";
			}
			else if (of.m_orderDate[i]["status"] == "2")
			{
				status += "���ͨ����ԤԼ�ɹ���";
			}
			else if (of.m_orderDate[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ�ܣ�";
			}
			else if (of.m_orderDate[i]["status"] == "0")
			{
				status += "ȡ��ԤԼ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

void Student::showAllorder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "ԤԼ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << "��" << i + 1 << "��ԤԼ��¼��" << endl;
		cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
		cout << "    ʱ��Σ�";
		if (of.m_orderDate[i]["interval"] == "1")cout << "����";
		else cout << "����";
		cout << "   ѧ�ţ�" << of.m_orderDate[i]["stuId"];
		cout << "   ������" << of.m_orderDate[i]["stuName"];
		cout << "   ������ţ�" << of.m_orderDate[i]["roomId"];
		string status = "   ԤԼ״̬��";
		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "�����.....";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "���ͨ����ԤԼ�ɹ���";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ�ܣ�";
		}
		else if (of.m_orderDate[i]["status"] == "0")
		{
			status += "ȡ��ԤԼ��";
		}
		cout << status << endl;
	}
	cout << "����ԤԼ��¼����ʾ��ϣ�" << endl;
	system("pause");
	system("cls");
	return;
}

void Student::cancelOrder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "ԤԼ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ɾ��������ԤԼ��¼���£�" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["stuId"] == this->m_id)
		{
			if (of.m_orderDate[i]["status"] == "1" || of.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << ++index << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
				cout << "    ʱ��Σ�" ;
				if (of.m_orderDate[i]["interval"] == "1")cout << "����";
				else cout << "����";
				cout << "   ������ţ�" << of.m_orderDate[i]["roomId"];
				string status = "   ԤԼ״̬��";
				if (of.m_orderDate[i]["status"] == "1")
				{
					status += "�����.....";
				}
				else if (of.m_orderDate[i]["status"] == "2")
				{
					status += "���ͨ����ԤԼ�ɹ���";
				}
				else if (of.m_orderDate[i]["status"] == "-1")
				{
					status += "���δͨ����ԤԼʧ�ܣ�";
				}
				else if (of.m_orderDate[i]["status"] == "0")
				{
					status += "ȡ��ԤԼ��";
				}
				cout << status << endl;
			}
		}
	}
	cout << "����������Ҫȡ����ԤԼ��¼��0��ʾ���أ���" << endl;
	int select = 0;
	cin >> select;
	while (select < 0 || select>v.size() || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "�����������������룺";
		cin >> select;
	}
	if (select == 0) {
		cout << "���سɹ�!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		of.m_orderDate[v[select - 1]]["status"] = "0";
		of.updateOrder();
		cout << "�ѳɹ�ȡ��ԤԼ��" << endl;
		system("pause");
		system("cls");
		return;
	}
}