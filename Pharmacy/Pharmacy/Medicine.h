#pragma once
#include <string>
#include "Date.h"

class Medicine
{
private:
	std::string name;
	float price;
	int quantity;
	Date expDate;//(int day,int month,int year);
public:
	Medicine();
	Medicine(std::string n,float p,int q,int d,int m,int y);
	void Display();
	bool isExpired(Date date);
	float getPrice();
	int getQuantity();
	std::string getName();
	~Medicine();
};

