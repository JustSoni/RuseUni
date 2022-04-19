#include "StdAfx.h"
#include "Circle.h"


CCircle::CCircle()
{

}

CCircle::CCircle(float r)
{
	radius=r;
}

void CCircle::setData()
{
	CFigure::setData();
	std::cout<<"Radius - >";
	std::cin>>radius;
}

void CCircle::display()
{
	std::cout<<"------------\n";
	CFigure::display();
	std::cout<<"Radius: "<<radius<<"\n";
	std::cout<<"------------\n";
}

float CCircle::perimeter()
{
	const int PI=3.14;
	return 2*PI*radius;
}

CCircle::~CCircle(void)
{
}
