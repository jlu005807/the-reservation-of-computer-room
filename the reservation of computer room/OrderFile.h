#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"globalFile.h"

using namespace std;

class OrderFile
{
public:
	OrderFile();


	void updateOrder();

	int m_size;

	map<int, map<string, string>>m_orderDate;
};