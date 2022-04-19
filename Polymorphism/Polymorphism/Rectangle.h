#pragma once
#include "Figure.h"
#include <iostream>
#include <string>

using namespace std;

class CRectangle : public CFigure
{
protected:
	float width;
	float height;
public:
	CRectangle();
	CRectangle(float,float,string);
	void setData();
	void display();
	float perimeter();
	string getColour();
	~CRectangle();
};

