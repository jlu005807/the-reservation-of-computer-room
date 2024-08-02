#pragma once
#include"Identity.h"
#include"student.h"
#include"teacher.h"
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string password);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();

	bool checkRepeat(string id, int type);

	void printStu(Student& s);
	void printTea(Teacher& t);
	
	void savefile();

	vector<Student>vStu;

	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};