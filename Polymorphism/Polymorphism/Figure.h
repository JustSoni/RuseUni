#pragma once
#include <iostream>
#include <string>

using namespace std;

class CFigure
{
protected:
	string colour;
public:
	CFigure();
	CFigure(string);
	virtual void setData();
	virtual void display();
	virtual float perimeter()=0;
	~CFigure();
};

