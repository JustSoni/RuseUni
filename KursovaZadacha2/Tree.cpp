#include "StdAfx.h"
#include "Tree.h"

#include <iostream>
#include <string>

using namespace std;

CTree::CTree():CPlant("NULL",0,0)
{
	height=0;
	type="NULL";
}

CTree::CTree(float h,string t,string name,float price,int count):CPlant(name,price,count)
{
	height=h;
	type=t;
}

void CTree::setData()
{
	CPlant::setData();
	std::cout<<"Height-> ";
	std::cin>>height;
	std::cout<<"Type-> ";
	std::cin>>type;
}

void CTree::display()
{
	CPlant::display();
	std::cout<<"Height: "<<height<<"\n";
	std::cout<<"Type: "<<type<<"\n";
}

string CTree::getType()
{
	return type;
}

CTree::~CTree()
{
}
