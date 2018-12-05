/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This class implementation file contains the member function definitions for the Ant class.
***************************************************************************************************************/

#include "Ant.hpp"
#include <iostream>
#include <time.h>		// For struct timespec

using std::cout;
using std::cin;
using std::endl;

/***************************************************************************************************************
** Description: Ant class constructor takes in a pointer to a Board object, the initial position of the ant
** (i.e. row and column) on the board array, its initial facing direction, and the specified target number
** of steps the simluation should take. The constructor calls the necessary functions to initialize these
** values of an Ant class object.
***************************************************************************************************************/
Ant::Ant(Board *inputBoard, int initialRow, int initialCol, char facingDirectionInput, int inputCount)
{
	board = inputBoard;
	setCurrentRow(initialRow);
	setCurrentCol(initialCol);
	setFacingDirection(facingDirectionInput);
	setCount(inputCount);
}

/***************************************************************************************************************
** Description: turnRight changes the facingDirection of the ant 90 degrees clockwise, based on the four
** cardinal directions.
***************************************************************************************************************/
void Ant::turnRight()
{
	switch (getFacingDirection())
	{
	case 'N': setFacingDirection('E');
		break;
	case 'E': setFacingDirection('S');
		break;
	case 'S': setFacingDirection('W');
		break;
	case 'W': setFacingDirection('N');
		break;
	}
}

/***************************************************************************************************************
** Description: turnLeft changes the facingDirection of the ant 90 degrees counter-clockwise, based on the four
** cardinal directions.
***************************************************************************************************************/
void Ant::turnLeft()
{
	switch (getFacingDirection())
	{
	case 'N': setFacingDirection('W');
		break;
	case 'E': setFacingDirection('N');
		break;
	case 'S': setFacingDirection('E');
		break;
	case 'W': setFacingDirection('S');
		break;
	}
}

/***************************************************************************************************************
** Description: moveNorth attempts to move the ant one unit up in the array. If it is successful, a true bool
** value is returned. If the ant is at the edge of the array and cannot move forward without being out of
** bound of the array, then the move is not made and a false bool value is returned.
***************************************************************************************************************/
bool Ant::moveNorth()
{
	bool moveSuccessful = false;

	if ((getCurrentRow() - 1) >= 1)
	{
		setCurrentRow(getCurrentRow() - 1);
		moveSuccessful = true;
	}

	return moveSuccessful;
}

/***************************************************************************************************************
** Description: moveSouth attempts to move the ant one unit down in the array. If it is successful, a true bool
** value is returned. If the ant is at the edge of the array and cannot move forward without being out of
** bound of the array, then the move is not made and a false bool value is returned.
***************************************************************************************************************/
bool Ant::moveSouth()
{
	bool moveSuccessful = false;

	if ((getCurrentRow() + 1) <= (board->getRow()))
	{
		setCurrentRow(getCurrentRow() + 1);
		moveSuccessful = true;
	}

	return moveSuccessful;
}

/***************************************************************************************************************
** Description: moveWest attempts to move the ant one unit left in the array. If it is successful, a true bool
** value is returned. If the ant is at the edge of the array and cannot move forward without being out of
** bound of the array, then the move is not made and a false bool value is returned.
***************************************************************************************************************/
bool Ant::moveWest()
{
	bool moveSuccessful = false;

	if ((getCurrentCol() - 1) >= 1)
	{
		setCurrentCol(getCurrentCol() - 1);
		moveSuccessful = true;
	}

	return moveSuccessful;
}

/***************************************************************************************************************
** Description: moveEast attempts to move the ant one unit right in the array. If it is successful, a true bool
** value is returned. If the ant is at the edge of the array and cannot move forward without being out of
** bound of the array, then the move is not made and a false bool value is returned.
***************************************************************************************************************/
bool Ant::moveEast()
{
	bool moveSuccessful = false;

	if ((getCurrentCol() + 1) <= (board->getCol()))
	{
		setCurrentCol(getCurrentCol() + 1);
		moveSuccessful = true;
	}

	return moveSuccessful;
}

/***************************************************************************************************************
** Description: moveNorth attempts to move the ant one unit forward in whichever way the ant is facing. It
** makes the call to the corresponding move function. If the move is successful, a true bool
** value is returned. If the ant is at the edge of the array and cannot move
** forward without being out of bound of the array, then the move is not made and a false bool value is returned.
***************************************************************************************************************/
bool Ant::moveForward()
{
	bool moveSuccessful;

	switch(getFacingDirection())
	{
	case 'N': moveSuccessful = moveNorth();
		break;
	case 'E': moveSuccessful = moveEast();
		break;
	case 'S': moveSuccessful = moveSouth();
		break;
	case 'W': moveSuccessful = moveWest();
		break;
	}

	return moveSuccessful;
}

/***************************************************************************************************************
** Description: getCellState returns the value stored at the element of the board array that the ant is on
** (i.e. currently occupying).
***************************************************************************************************************/
char Ant::getCellState()
{
	return	board->getCell(getCurrentRow(), getCurrentCol());
}

/***************************************************************************************************************
** Description: setCellState sets the value of the element of the board array that the ant is on to the char
** that was input into the function's parameter.
***************************************************************************************************************/
void Ant::setCellState(char inputChar)
{
	board->setCell(inputChar, getCurrentRow(), getCurrentCol());
}

/***************************************************************************************************************
** Description: setCurrentRow changes the row value the ant is occupying to the input value.
***************************************************************************************************************/
void Ant::setCurrentRow(int inputRow)
{
	currentRow = inputRow;
}

/***************************************************************************************************************
** Description: setCurrentCol changes the column value the ant is occupying to the input value.
***************************************************************************************************************/
void Ant::setCurrentCol(int inputCol)
{
	currentCol = inputCol;
}

/***************************************************************************************************************
** Description: setFacingDirection changes the facing direction of the ant to the input value.
***************************************************************************************************************/
void Ant::setFacingDirection(char facingDirectionInput)
{
	facingDirection = facingDirectionInput;
}

/***************************************************************************************************************
** Description: getCurrentRow returns the current row the ant is occupying.
***************************************************************************************************************/
int Ant::getCurrentRow()
{
	return currentRow;
}

/***************************************************************************************************************
** Description: getCurrentCol returns the current column the ant is occupying.
***************************************************************************************************************/
int Ant::getCurrentCol()
{
	return currentCol;
}

/***************************************************************************************************************
** Description: getFacingDirection returns the current facing direction of the ant.
***************************************************************************************************************/
char Ant::getFacingDirection()
{
	return facingDirection;
}

/***************************************************************************************************************
** Description: setCount initializes the count variable used to keep track of the number of steps the simluation
** will make.
***************************************************************************************************************/
void Ant::setCount(int inputCount)
{
	count = inputCount;
}

/***************************************************************************************************************
** Description: getCount returns the value of the count data member.
***************************************************************************************************************/
int Ant::getCount()
{
	return count;
}

/***************************************************************************************************************
** Description: decrementCount is used to decrement the count data member.
***************************************************************************************************************/
void Ant::decrementCount()
{
	setCount(getCount() - 1);
}

/***************************************************************************************************************
** Description: displayBoardWithAnt prints the board array with accompanying row and column labels,
** along with the ant (symbolized with a '@' char) in the cell (element) it is occupying.
***************************************************************************************************************/
void Ant::displayBoardWithAnt()
{
	//display top number labels
	cout << "       ";
	for (int i = 0; i < board->getCol(); i++)
	{
		if (i < 9)
		{
			cout << "0";
		}
		cout << (i + 1) << "  ";
	}
	cout << endl;

	//display array with side number labels
	for (int i = 0; i < board->getRow(); i++)
	{
		if (i < 9)
		{
			cout << "0";
		}
		cout << (i + 1) << " |   ";
		for (int j = 0; j < board->getCol(); j++)
		{
			//displays the ant '@' at the cell it is currently occupying
			if (getCurrentRow() == (i + 1) && getCurrentCol() == (j + 1))
			{
				//cout << "@" << "   ";

				if (getFacingDirection() == 'N') {
					cout << "^";
				} else if (getFacingDirection() == 'E') {
					cout << ">";
				} else if (getFacingDirection() == 'S') {
					cout << "v";
				} else if (getFacingDirection() == 'W') {
					cout << "<";
				}
				cout << "   ";
			}
			else
			{
				cout << board->getCell(i+1,j+1) << "   ";
			}
		}
		cout << "|" << endl;
	}
}

/***************************************************************************************************************
** Description: displayInstructionWithWait prints out the instructions to the screen and informs the user
** the rules that the simluation will follow. After the user reads this, they will need to press [Enter] key
** to continue.
***************************************************************************************************************/
void Ant::displayInstructionsWithWait()
{
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "The ant will follow two simple rules in this simulation: " << endl;
	cout << "1) If on a white square, the ant will change it to a black square, turn right 90 degrees, and move forward." << endl;
	cout << "2) If on a black square, the ant will change it to a white square, turn left 90 degrees, and move forward." << endl;
	cout << "NOTE: If a move forward cannot be performed (i.e. at a wall), then the ant will turn 90 degrees again" << endl;
	cout << "in same spin direction and attempt a move forward. The ant will repeat this until a move forward is possible." << endl << endl;

	cout << "White squares are designated with \"_\"." << endl;
	cout << "Black squares are designated with \"#\"." << endl << endl;
	cout << "The ant will be shown as \"^\", \">\", \"v\", or \"<\" depending on its facing direction." << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Please press [Enter] to continue." << endl;
	cin.ignore();
}

/***************************************************************************************************************
** Description: runSimluation runs the simulation of Langton's Ant using the defined data members of the object
** (i.e. pointer to board array, ant's initial starting direction and location, and the number of steps the
** simulation will run for). It makes the necessary function call to iterate the simluation until it has
** exhausted the number of steps. There is a special case it considers. If the user enters a 1x1 array, it
** informs the user this will result in an infinite loop and then stops the program.
***************************************************************************************************************/
void Ant::runSimulation()
{
	system("clear");
	displayBoardWithAnt();
	cout << "Steps remaining: " << getCount() << endl;

	//special case if array is 1x1
	if (board->getRow() == 1 && board->getCol() == 1)
	{
		cout << endl << "This won't be an interesting simulation since the ant will have no space to move." << endl;
	}
	else
	{
		while (getCount() > 0)
		{
			// Sleep for 0.5s
			struct timespec req, rem;
			req.tv_sec = 0;
			req.tv_nsec = 500000000;
			nanosleep(&req, &rem);

			bool moveSuccessful = false;

			if (getCellState() == '_')
			{
				setCellState('#');
				while (!moveSuccessful)
				{
					turnRight();
					moveSuccessful = moveForward();
				}
			}
			else if (getCellState() == '#')
			{
				setCellState('_');
				while (!moveSuccessful)
				{
					turnLeft();
					moveSuccessful = moveForward();
				}
			}

			decrementCount();

			system("clear");
			displayBoardWithAnt();
			cout << "Steps remaining: " << getCount() << endl;
		}
	}
}
