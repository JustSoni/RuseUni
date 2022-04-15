#pragma once
#include <string>

using namespace std;

class CGuest
{
private:
	string name;
	string EGN;
	int maritalStatus;
	int staysCount;
	float bedPrice;
	string settlement;
public:
	CGuest();
	CGuest(string, string, int, int, float, string);
	void Display();
	void SetData();
	string getGender();
	string getName();
	string getSettlement();
	int getMaritalStatus();
	int getBirthYear();
	float getTotalAmount();
	~CGuest();
};

