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
	cout << "欢迎教师：" << this->m_name << "登录！" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        1-查看所有预约               |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        2-审核预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                        0-注销登录                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "请选择您的操作：";
	return;
}

void Teacher::showAllorder()
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
		cout << "    时间段：" << of.m_orderDate[i]["interval"];
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

void Teacher::valiOrder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "预约记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "待审核的预约记录如下：" << endl;
	int flag = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1" )
		{
			flag = 1;
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_orderDate[i]["date"];
			cout << "    时间段：" ;
			if (of.m_orderDate[i]["interval"] == "1")cout << "上午";
			else cout << "下午";
			cout << "   机房编号：" << of.m_orderDate[i]["roomId"];
			string status = "   预约状态：";				
			status += "审核中.....";
			cout << status << endl;
		}

	}
	if (flag)cout << "请输入您需要审核的预约记录（0代表返回）：" << endl;
	else {
		cout << "无需要审核的预约记录" << endl;
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
		cout << "请输入审核结果：" << endl;
		cout << "   1.通过" << endl;
		cout << "   2.不通过" << endl;
		cin >> ret;
		while (ret < 1 || ret> 2 || cin.fail())
		{
			cin.ignore();
			cin.clear();
			while (char c = getchar() != '\n');
			cout << "输入有误，请重新输入：";
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
		cout << "审核完毕！" << endl;
		system("pause");
		system("cls");
		return;
	}
}

