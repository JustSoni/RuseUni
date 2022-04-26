#pragma once
#include <iostream>
#include <string>

using namespace std;

class CPlant
{
protected:
	string name;
	float price;
	int count;
public:
	CPlant();
	CPlant(string,float,int);
	virtual void setData();
	virtual void display();
	float getPrice();
	~CPlant();
};

