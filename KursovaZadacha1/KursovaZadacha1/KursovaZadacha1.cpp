// KursovaZadacha1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Guest.h"

#include<iostream>

int DisplayMenu()
{
	std::cout << "________________________________\n";
	int option;
	std::cout << "1 - Add new guest\n";
	std::cout << "2 - Display all guests\n";
	std::cout << "3 - Display data for all people from given settlement who are married\n";
	std::cout << "4 - Create new database of unmarried men from given settlement and born at a given year\n";
	std::cout << "Option -> ";
	std::cin >> option;
	std::cout << "________________________________\n";
	return option;
}

void CalculateMoneyFromSettlement(CGuest guests[], int count)
{
	std::cout << "________________________________\n";
	float total = 0;
	string settlementToCheck;
	std::cout << "Settlement? -> ";
	cin.ignore();
	std::getline(cin, settlementToCheck);

	for (int i = 0; i < count; i++)
	{
		if ((guests[i].getSettlement() == settlementToCheck) && (guests[i].getMaritalStatus() == 2))
		{
			std::cout << guests[i].getName() << " have paid " << guests[i].getTotalAmount() << " BGN total.\n";
		}
	}
	if (total == 0)
	{
		std::cout << "There is no married guest from " << settlementToCheck << "\n";
	}
	std::cout << "________________________________\n";
}

int main()
{

	std::cout << "0---------STARTING-APP---------0\n";

	CGuest guests[100];
	int gCount = 0;
	CGuest guestsFromSettlement[100];
	int gSettlementCount = 0;

	while (true)
	{
		switch (DisplayMenu())
		{
		case 1:
		{
			guests[gCount++].SetData();
			break;
		}
		case 2:
		{
			if (gCount == 0)
			{
				std::cout << "There are no people in the database.\n";
				break;
			}

			for (int i = 0; i < gCount; i++)
			{
				guests[i].Display();
			}
			break;
		}
		case 3:
		{
			if (gCount == 0)
			{
				std::cout << "There are no people in the database.\n";
				break;
			}
			CalculateMoneyFromSettlement(guests, gCount);
			break;
		}
		case 4:
		{
			if (gCount == 0)
			{
				std::cout << "There are no people in the database.\n";
				break;
			}

			gSettlementCount = 0;

			int birthYear;
			std::cout << "Year -> ";
			std::cin >> birthYear;

			for (int i = 0; i < gCount; i++)
			{
				if (guests[i].getGender() == "Male" && guests[i].getMaritalStatus() == 1 && guests[i].getBirthYear() == birthYear)
				{
					guestsFromSettlement[gSettlementCount++] = guests[i];
				}
			}

			std::cout << "0---------UNMARRIED-MEN--------0\n";
			for (int i = 0; i < gSettlementCount; i++)
			{
				guestsFromSettlement[i].Display();
			}

			break;
		}
		}
	}

	return 0;
}
