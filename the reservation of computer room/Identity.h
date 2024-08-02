#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include"ComputerRoom.h"
#include"globalFile.h"
#include"OrderFile.h"
using namespace std;

class Identity
{
public:
	virtual void operMenu() = 0;
	string m_name;
	string m_password;
};