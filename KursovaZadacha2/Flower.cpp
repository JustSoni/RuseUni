#include "StdAfx.h"
#include "Flower.h"

#include <iostream>
#include <string>

using namespace std;

CFlower::CFlower()
{
	colour="NULL";
}

CFlower::CFlower(string c,string name,float price,int count):CPlant(name,price,count)
{
	colour=c;
}

void CFlower::setData()
{
	CPlant::setData();
	std::cout<<"Colour-> ";
	std::cin>>colour;
}

void CFlower::display()
{
	CPlant::display();
	std::cout<<"Colour: "<<colour<<"\n";
}

CFlower::~CFlower()
{
}
