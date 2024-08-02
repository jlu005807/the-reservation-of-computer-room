#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(string empid, string name, string password)
{
	this->m_empid = empid;
	this->m_name = name;
	this->m_password = password;
}

void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        1-�鿴����ԤԼ               |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        2-���ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        0-ע����¼                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
	return;
}

void Teacher::showAllorder()
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
		cout << "    ʱ��Σ�" << of.m_orderDate[i]["interval"];
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

void Teacher::valiOrder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "ԤԼ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "����˵�ԤԼ��¼���£�" << endl;
	int flag = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1" )
		{
			flag = 1;
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
			cout << "    ʱ��Σ�" ;
			if (of.m_orderDate[i]["interval"] == "1")cout << "����";
			else cout << "����";
			cout << "   ������ţ�" << of.m_orderDate[i]["roomId"];
			string status = "   ԤԼ״̬��";				
			status += "�����.....";
			cout << status << endl;
		}

	}
	if (flag)cout << "����������Ҫ��˵�ԤԼ��¼��0�����أ���" << endl;
	else {
		cout << "����Ҫ��˵�ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int select = 0;
	int ret = 0;
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
		cout << "��������˽����" << endl;
		cout << "   1.ͨ��" << endl;
		cout << "   2.��ͨ��" << endl;
		cin >> ret;
		while (ret < 1 || ret> 2 || cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "�����������������룺";
			cin >> ret;
		}

		if (ret == 1)
		{
			of.m_orderDate[v[select - 1]]["status"] = "2";
		}
		else
		{
			of.m_orderDate[v[select - 1]]["status"] = "-1";
		}

		of.updateOrder();
		cout << "�����ϣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
}

