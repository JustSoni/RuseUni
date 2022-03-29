#pragma once
class Date
{
private:
	int day,month,year;
public:
	Date();
	Date(int d,int m,int y);
	void SetData();
	void Display();
	int getDay();
	int getMonth();
	int getYear();
	~Date(void);
};

