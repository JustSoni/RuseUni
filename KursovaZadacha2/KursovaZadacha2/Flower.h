#pragma once
#include "Plant.h"

#include <iostream>
#include <string>

using namespace std;

class CFlower: public CPlant
{
protected:
	string colour;
public:
	CFlower();
	CFlower(string,string,float,int);
	void setData();
	void display();
	~CFlower();
};

