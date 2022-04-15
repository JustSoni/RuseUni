#include "StdAfx.h"
#include "Guest.h"
#include"iostream"

using namespace std;

string CGuest::getGender()
{
	string egn = this->EGN;
	string gender = "Male";

	int digit = egn.at(8) - '0';

	if (digit % 2 == 1)
	{
		gender = "Female";
	}

	return gender;
}

int CGuest::getMaritalStatus()
{
	return this->maritalStatus;
}

int CGuest::getBirthYear()
{
	int year = stoi(EGN.substr(0, 2));
	int month = stoi(EGN.substr(2, 2));

	if (month < 13)
	{
		year += 1900;
	}
	else if (month < 33)
	{
		year += 1800;
	}
	else
	{
		year += 2000;
	}


	return year;
}

string CGuest::getSettlement()
{
	return this->settlement;
}

string CGuest::getName()
{
	return this->name;
}

float CGuest::getTotalAmount()
{
	return this->bedPrice * this->staysCount;
}

void CGuest::Display()
{
	std::cout << "______________INFO______________\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "EGN: " << EGN << "\n";
	std::cout << "Marital Status: ";
	if (maritalStatus == 1)
	{
		std::cout << "Unmarried\n";
	}
	else
	{
		std::cout << "Married\n";
	}
	std::cout << "Overnight stays: " << staysCount << "\n";
	std::cout << "Bed price: " << bedPrice << "\n";
	std::cout << "Settlement: " << settlement << "\n";
	std::cout << "________________________________\n";
}

void CGuest::SetData()
{
	std::cout << "________SETTING NEW DATA________\n";
	std::cin.ignore();
	std::cout << "Name -> "; std::getline(cin, name);
	std::cout << "EGN -> "; std::cin >> EGN;
	std::cout << "Marital Status(1 - Unmarried, 2 - Married) -> "; std::cin >> maritalStatus;
	std::cout << "Overnight stays -> "; std::cin >> staysCount;
	std::cout << "Bed price -> "; std::cin >> bedPrice;
	std::cin.ignore();
	std::cout << "Settlement -> "; std::getline(cin, settlement);
	std::cout << "________________________________\n";
}

CGuest::CGuest()
{
	this->name = "null Name";
	this->EGN = "null EGN";
	this->maritalStatus = 1;
	this->staysCount = 0;
	this->bedPrice = 0;
	this->settlement = "null Settlement";
}

CGuest::CGuest(string name, string egn, int mStatus, int sCount, float bPrice, string settlement)
{
	this->name = name;
	this->EGN = egn;
	this->maritalStatus = mStatus;
	this->staysCount = sCount;
	this->bedPrice = bPrice;
	this->settlement = settlement;
}


CGuest::~CGuest()
{

}
