/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This class specification file contains the Ant class declaration. It represents the ant in the Langton's
** Ant simulation. The class keeps track of the ant's position (row and column) and facing direction. It
** takes in pointer to a Board object and uses the Board class member functions to get and set values of
** cells as the simluation runs. This Ant class has a series of function to move the ant and change its
** facing direction. It also has a count member variable and accompanying functions to keep track of the
** number of steps taken and decrements count accordingly. This class also has a function that can print
** the board to screen with the ant displayed. The runSimluation function contains the instructions to perform
** the Langton's Ant simulation using its class members and the Board class object.
***************************************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

class Ant
{
private:
	Board *board;
	int currentRow, currentCol;
	char facingDirection;
	int count;

public:
	Ant(Board *inputBoard, int initialRow, int initialCol, char facingDirectionInput, int inputCount);

	void turnRight();
	void turnLeft();
	
	bool moveNorth();
	bool moveSouth();
	bool moveWest();
	bool moveEast();

	bool moveForward();

	char getCellState();
	void setCellState(char inputChar);

	void setCurrentRow(int inputRow);
	void setCurrentCol(int inputCol);
	void setFacingDirection(char facingDirectionInput);

	int getCurrentRow();
	int getCurrentCol();
	char getFacingDirection();

	void setCount(int inputCount);
	int getCount();
	void decrementCount();

	void displayInstructionsWithWait();
	void displayBoardWithAnt();

	void runSimulation();
};
#endif