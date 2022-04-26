#include "StdAfx.h"
#include "Plant.h"


CPlant::CPlant()
{
	name="NULL";
	price=0;
	count=0;
}

CPlant::CPlant(string n, float p, int c)
{
	name=n;
	price=p;
	count=c;
}

void CPlant::setData()
{
	std::cout<<"Name -> ";
	std::cin>>name;
	std::cout<<"Price -> ";
	std::cin>>price;
	std::cout<<"Count -> ";
	std::cin>>count;
}

void CPlant::display()
{
	std::cout<<"Name: "<<name<<"\n";
	std::cout<<"Price: "<<price<<"\n";
	std::cout<<"Count: "<<count<<"\n";
}

float CPlant::getPrice()
{
	return price;
}

CPlant::~CPlant()
{
}
