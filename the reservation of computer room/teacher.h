#pragma once
#include"Identity.h"

class Teacher :public Identity
{
public:

	Teacher();

	Teacher(string empId, string name, string password);

	virtual void operMenu();

	void showAllorder();

	void valiOrder();//…Û∫À‘§‘º

	string m_empid;

};