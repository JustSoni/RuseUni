#include "StdAfx.h"
#include "Trap.h"


CTrap::CTrap():CGameObject()
{
	damage = 0;
}

CTrap::CTrap(int d, int x1,int y1,string n,char sn):CGameObject(x1,y1,n,sn)
{
	damage = d;
}

int CTrap::getDamage()
{
	return damage;
}

void CTrap::setData()
{
	CGameObject::setData();
	std::cout<<"Damage -> ";
	std::cin>>damage;
}

void CTrap::display()
{
	CGameObject::display();
	std::cout<<"Damage: "<<damage<<"\n";
}

CTrap::~CTrap()
{
}
