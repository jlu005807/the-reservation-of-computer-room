#pragma once
#include"Identity.h"

class Teacher :public Identity
{
public:

	Teacher();

	Teacher(string empId, string name, string password);

	virtual void operMenu();

	void showAllorder();

	void valiOrder();//���ԤԼ

	string m_empid;

};