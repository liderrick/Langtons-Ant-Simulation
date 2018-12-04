/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This implementation file contains definitions for functions that handle the random number generator.
***************************************************************************************************************/

#include "randomFunctions.hpp"

#include <cstdlib>		//for srand and rand functions
#include <ctime>		//for time functions

/***************************************************************************************************************
** Description: setSrand seeds the random number generator with time(NULL). It should run only once per
** program before any function calls are made to the rand function.
***************************************************************************************************************/
void setSrand()
{
	srand(time(NULL));
}

/***************************************************************************************************************
** Description: randomNumber takes in two integers as arguments and sets the low and high limit of the range
** it should return a random number within. It uses the function rand and returns a integer value within the
** range specified by the parameters.
***************************************************************************************************************/
int randomNumber(int low, int high)
{
	return ((rand() % high) + low);
}

/***************************************************************************************************************
** Description: randomDirection randomly chooses one of the four cardinal directions and returns it as a char.
** It does this by generating a random number between 1-4 and uses this to choose 1 of 4 possible choices of
** char that represents the cardinal directions.
***************************************************************************************************************/
char randomDirection()
{
	char direction;
	int rand = randomNumber(1, 4);

	switch (rand)
	{
	case 1: direction = 'N';
		break;
	case 2: direction = 'E';
		break;
	case 3: direction = 'S';
		break;
	case 4: direction = 'W';
		break;
	}

	return direction;
}

/***************************************************************************************************************
** Description: randomStartAndDirection randomly chooses starting row, starting column, and starting facing
** directions when provided the size of the board array (i.e. rows and column) as its parameters. It returns
** the randomly chosen values as reference.
***************************************************************************************************************/
void randomStartAndDirection(int &startingRow, int &startingCol, char &startingFacingDirection, const int userRow, const int userCol)
{
	startingRow = randomNumber(1, userRow);
	startingCol = randomNumber(1, userCol);
	startingFacingDirection = randomDirection();
}