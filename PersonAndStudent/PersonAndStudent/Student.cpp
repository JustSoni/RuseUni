#include "StdAfx.h"
#include "Student.h"
#include"Person.h"
#include<iostream>

using namespace std;

Student::Student():Person()
{
	this->FN="00000";
	for(int i=0;i<5;i++)
	{
		this->studentMarks[i]=0;
	}
}
Student::Student(string name,string egn,string fn, int marks[5]):Person(name,egn)
{
	this->FN=fn;
	for(int i=0;i<5;i++)
	{
		this->studentMarks[i]=marks[i];
	}
}

void Student::display()
{
	Person::display();
	std::cout<<"FN: "<<FN<<std::endl;
	std::cout<<"Marks: ";
	for(int i=0;i<5;i++)
	{
		std::cout<<studentMarks[i]<<" ";
	}
	std::cout<<std::endl;
}

void Student::setData()
{
	Person::setData();
	std::cout<<"FN -> ";
	std::cin>>FN;
	std::cout<<"Marks";
	for(int i=0;i<5;i++)
	{
		std::cout<<"Mark["<<i<<"] - > ";
		std::cin>>studentMarks[i];
	}
}

double Student::getAverage()
{
	double average=0;
	for(int i=0;i<5;i++)
	{
		average+=studentMarks[i];
	}

	return average/5;

}

Student::~Student()
{
}
