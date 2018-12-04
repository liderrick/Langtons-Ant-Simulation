/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This class specification file contains the Board class declaration. It represents the board in which the
** ant will move about on. The class initializes a dynamic 2D array using the input sizes. It has a destructor
** that deletes the dynamically allocated array upon completion of the simulation. There are functions that
** gets the value of the cells (element) of the array, changes the cells, and prints the board array. There
** are also getter functions for the size of the array, i.e. row and columns.
***************************************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

const int DEFAULT_ROW = 11;
const int DEFAULT_COL = 11;

class Board
{
private:
	char **board;	//double-pointer for dynamic 2D array
	int row;
	int col;

public:
	Board(int inputRow = DEFAULT_ROW, int inputCol = DEFAULT_COL);
	~Board();

	void setCell(char inputChar, int selectedRow, int selectedCol);
	char getCell(int selectedRow, int selectedCol);

	int getRow();
	int getCol();

	void displayBoard();
};

#endif