/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This program runs a simple simulation of Langton's Ant. The user chooses the size of board (array) for
** the simulation and then has the option to choose the starting position and facing direction of the ant or
** allow the program to randomly choose for them. The user will also specify the number of steps that wish
** the program will run for. The program then runs the stimulation until it has reached the required number
** of steps. The only special case it considers is when the board is a 1x1 array. In this case, it notifies
** the user that this will result in an infinite loop because the ant will have no where to go. Thus, it is not ran.
***************************************************************************************************************/

#include <iostream>
#include <string>

#include "Board.hpp"
#include "Ant.hpp"
#include "menu.hpp"
#include "randomFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{	
	int userRow, userCol;
	int startingRow, startingCol;
	int chosenNumberOfSteps;

	char startingFacingDirection;
	bool randomStartingPositionBool;

	if (mainMenu() == true)
	{
		menuPromptArraySize(userRow, userCol);
		Board board(userRow, userCol);	//constructs the Board object
		board.displayBoard();

		randomStartingPositionBool = menuPromptRandomStartPosition();

		if (randomStartingPositionBool)
		{
			setSrand();	//set seed for srand() function
			randomStartAndDirection(startingRow, startingCol, startingFacingDirection, userRow, userCol);

			cout << "The program randomly chosen the ant to start at row " << startingRow << " and column " << startingCol << " facing ";
			cout << directionCharToString(startingFacingDirection) << "." << endl;
		}
		else
		{
			menuPromptStartPosition(startingRow, startingCol, startingFacingDirection, userRow, userCol);
		}

		chosenNumberOfSteps = menuPromptNumberOfSteps();

		//Constructs the Ant object
		Ant ant(&board, startingRow, startingCol, startingFacingDirection, chosenNumberOfSteps);

		ant.displayInstructionsWithWait();
		ant.runSimulation();

		cout << "This simulation of Langton's Ant has concluded." << endl;
		cout << "Thank you for playing." << endl;
	}

	return 0;
}
