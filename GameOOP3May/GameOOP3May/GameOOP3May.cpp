// GameOOP3May.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Game.h"
#include "Player.h"
#include "Goods.h"
#include "Trap.h"
#include "GameObject.h"

#include <iostream>
#include <string>
#include <vector>

void displayMenu()
{
	std::cout<<"Menu\n";
	std::cout<<"1 - Create a Player\n";
	std::cout<<"2 - Create a Trap\n";
	std::cout<<"3 - Create Goods\n";
	std::cout<<"4 - Move Player(name) to coords(x,y)\n";
	std::cout<<"Option -> ";
}

int main()
{
	CGame game(10,10);
	
	int option = 1;

	while(option != 0)
	{
		displayMenu();
		std::cin>>option;

		switch(option)
		{
		case 1:
			game.addObject("Player");
			break;
		case 2:
			game.addObject("Trap");
			break;
		case 3:
			game.addObject("Goods");
			break;
		case 4:
			game.movePlayer();
			break;
		}

		system("CLS");
		game.displayBoard();
	}
}

