#pragma once
#include "Plant.h"

#include <iostream>
#include <string>

using namespace std;

class CTree:public CPlant
{
protected:
	float height;
	string type;
public:
	CTree();
	CTree(float,string,string,float,int);
	void setData();
	void display();
	string getType();
	~CTree();
};

