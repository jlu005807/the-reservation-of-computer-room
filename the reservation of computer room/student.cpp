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
		cout << "文件不存在或文件读取失败!" << endl;

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
	cout << "欢迎学生：" << this->m_name << "登录！" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        1-申请预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        2-查看我的预约               |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        3-查看所有预约               |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        4-取消预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        0-注销登录                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "请选择您的操作：";
	return;
}

void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请选择申请预约的时间：" << endl;
	cout << "1.周一 2.周二 3.周三 4.周四 5.周五 0.返回" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	cin >> date;
	while (date<0||date>5||cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "输入有误，请重新输入：";
		cin >> date;
	}
	if (date == 0)
	{
		cout << "返回成功!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请选择申请预约的时间段：" << endl;
	cout << "1.上午（8：00 - 12：00）   2.下午（14：00 - 18:00） 0.返回" << endl;
	
	cin >> interval;
	while (interval < 0 || interval>2 || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "输入有误，请重新输入：";
		cin >> interval;
	}
	if (interval == 0)
	{
		cout << "返回成功!" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	
	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_Comid << "号机房容量为：" << vCom[i].m_MaxNum << endl;
	}
	cout << "----------------------------------------------------------" << endl;

	cin >> room;
	while (room < 1 || room>vCom.size() || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "输入有误，请重新输入：";
		cin >> room;
	}
	cout << endl;
	cout << "预约成功！审核中......" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " interval:" << interval << " stuId:" << this->m_id << " stuName:" << this->m_name << " roomId:" << room << " status:"/*预约状态*/ << 1 << " " << endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "预约记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		/*cout << of.m_orderDate[i]["stuId"] << endl;*/
		if (of.m_orderDate[i]["stuId"] == this->m_id)
		{
			cout << "预约日期：周" << of.m_orderDate[i]["date"];
			cout << "    时间段：" ;
			if (of.m_orderDate[i]["interval"] == "1")cout << "上午";
			else cout << "下午";
			cout << "   机房编号：" << of.m_orderDate[i]["roomId"];
			string status = "   预约状态：";
			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "审核中.....";
			}
			else if (of.m_orderDate[i]["status"] == "2")
			{
				status += "审核通过，预约成功！";
			}
			else if (of.m_orderDate[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败！";
			}
			else if (of.m_orderDate[i]["status"] == "0")
			{
				status += "取消预约！";
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
		cout << "预约记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << "第" << i + 1 << "条预约记录：" << endl;
		cout << "预约日期：周" << of.m_orderDate[i]["date"];
		cout << "    时间段：";
		if (of.m_orderDate[i]["interval"] == "1")cout << "上午";
		else cout << "下午";
		cout << "   学号：" << of.m_orderDate[i]["stuId"];
		cout << "   姓名：" << of.m_orderDate[i]["stuName"];
		cout << "   机房编号：" << of.m_orderDate[i]["roomId"];
		string status = "   预约状态：";
		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "审核中.....";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "审核通过，预约成功！";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败！";
		}
		else if (of.m_orderDate[i]["status"] == "0")
		{
			status += "取消预约！";
		}
		cout << status << endl;
	}
	cout << "所有预约记录已显示完毕！" << endl;
	system("pause");
	system("cls");
	return;
}

void Student::cancelOrder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "预约记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的记录可以删除，您的预约记录如下：" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["stuId"] == this->m_id)
		{
			if (of.m_orderDate[i]["status"] == "1" || of.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << ++index << "、";
				cout << "预约日期：周" << of.m_orderDate[i]["date"];
				cout << "    时间段：" ;
				if (of.m_orderDate[i]["interval"] == "1")cout << "上午";
				else cout << "下午";
				cout << "   机房编号：" << of.m_orderDate[i]["roomId"];
				string status = "   预约状态：";
				if (of.m_orderDate[i]["status"] == "1")
				{
					status += "审核中.....";
				}
				else if (of.m_orderDate[i]["status"] == "2")
				{
					status += "审核通过，预约成功！";
				}
				else if (of.m_orderDate[i]["status"] == "-1")
				{
					status += "审核未通过，预约失败！";
				}
				else if (of.m_orderDate[i]["status"] == "0")
				{
					status += "取消预约！";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入您需要取消的预约记录（0表示返回）：" << endl;
	int select = 0;
	cin >> select;
	while (select < 0 || select>v.size() || cin.fail())
	{
		cin.ignore();
		cin.clear();
		while (char c = getchar() != '\n');
		cout << "输入有误，请重新输入：";
		cin >> select;
	}
	if (select == 0) {
		cout << "返回成功!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		of.m_orderDate[v[select - 1]]["status"] = "0";
		of.updateOrder();
		cout << "已成功取消预约！" << endl;
		system("pause");
		system("cls");
		return;
	}
}