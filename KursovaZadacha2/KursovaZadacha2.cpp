// KursovaZadacha2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu()
{//deciduous, coniferous - шир, игл
	std::cout<<"MENU\n";
	std::cout<<"1 - Add a new tree\n";
	std::cout<<"2 - Add a new flower\n";
	std::cout<<"3 - Show all plants\n";
	std::cout<<"4 - Show all coniferous trees\n";
	std::cout<<"5 - Create a new array with plants under 10$\n";
	std::cout<<"0 - Close app\n";
	std::cout<<"OPTION -> ";
}

int main()
{
	CPlant *plants[30];
	int nPlants = 0;

	CPlant *cheapPlants[30];
	int nCheap = 0;

	int option = 6;

	while (option != 0)
	{
		displayMenu();
		std::cin >> option;
		switch (option)
		{
		case 1:
			plants[nPlants]=new CTree;
			plants[nPlants]->setData();
			nPlants++;
			break;
		case 2:
			plants[nPlants]=new CFlower;
			plants[nPlants]->setData();
			nPlants++;
			break;
		case 3:
			for(int i = 0; i < nPlants; i++)
			{
				std::cout << "----------\n";
				plants[i]->display();
				std::cout << "----------\n";
			}
			break;
		case 4:
			for(int i = 0; i < nPlants; i++)
			{
				CTree* tree=dynamic_cast<CTree*>(plants[i]);
				if(tree!=nullptr)
				{
					if(tree->getType() == "coniferous" || tree->getType() == "Coniferous")
					{
						std::cout << "----------\n";
						tree->display();
						std::cout << "----------\n";
					}
				}
			}
			break;
		case 5:
			for(int i = 0; i < nPlants; i++)
			{
				if(plants[i]->getPrice() < 10)
				{
					cheapPlants[nCheap++]=plants[i];
				}
			}
			for(int i = 0; i < nCheap; i++)
			{
				std::cout << "----------\n";
				cheapPlants[i]->display();
				std::cout << "----------\n";
			}
			break;
		case 0:
			std::cout << "Closing app!\n";
			break;
		default:
			std::cout << "Invalid option!\n";
			break;
		}
	}


	return 0;
}

