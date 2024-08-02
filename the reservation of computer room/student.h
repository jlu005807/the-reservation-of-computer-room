#pragma once
#include"Identity.h"
using namespace std;


class Student :public Identity
{
public:
	Student();

	Student(string id, string name, string password);

	virtual void operMenu();

	void applyOrder();

	void showMyorder();

	void showAllorder();

	void cancelOrder();

	string m_id;

	vector<ComputerRoom> vCom;
};