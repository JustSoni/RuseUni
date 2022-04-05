#pragma once
#include <string>

using namespace std;

class Person
{
private:
	string name;
	string EGN;
public:
	Person();
	Person(string name,string egn);
	void display();
	void setData();
	~Person();
};

