#include "StdAfx.h"
#include "Medicine.h"
#include "Date.h"
#include"iostream"

Medicine::Medicine()
{
	name="Unknown";
	price=0;
	quantity=0;
	expDate = Date(1,1,1980);
}

Medicine::Medicine(std::string n,float p,int q,int d,int m,int y)
{
	name=n;
	price=p;
	quantity=q;
	expDate  = Date(d,m,y);
}

void Medicine::Display()
{
	std::cout<<"Name -> "<<name<<std::endl;
	std::cout<<"Price -> "<<price<<std::endl;
	std::cout<<"Quantity -> "<<quantity<<std::endl;
	std::cout<<"Date of expiration -> "; expDate.Display();
}

bool Medicine::isExpired(Date today)
{
	int expiryN=expDate.getDay()+expDate.getMonth()*30+expDate.getYear()*365;

	int todayN=today.getDay()+today.getMonth()*30+today.getYear()*365;

	return expiryN<todayN;
}

float Medicine::getPrice()
{
	return price;
}
int Medicine::getQuantity()
{
	return quantity;
}

std::string Medicine::getName()
{
	return name;
}

Medicine::~Medicine()
{
}
