/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This class implementation file contains the member function definitions for the Board class.
***************************************************************************************************************/

#include "Board.hpp"
#include <iostream>

using std::cout;
using std::endl;

/***************************************************************************************************************
** Description: This Board class constructor uses input size parameters (i.e. number of rows and columns)
** to initializes a dynamic 2D array. It has default values so that it is a default constructor.
***************************************************************************************************************/
Board::Board(int inputRow /* = 11 DEFAULT_ROW*/, int inputCol /* = 11 DEFAULT_COL*/)
{
	row = inputRow;
	col = inputCol;
	
	//creates 2d char array
	board = new char *[row];
	for (int i = 0; i < row; i++)
	{
		board[i] = new char[col];
	}

	//initialize 2d char array to contain blank spaces
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = '_';
		}
	}
}

/***************************************************************************************************************
** Description: This Board class destructor frees the memory that was dynamically allocated for the 2D array
** upon completion of use of the object.
***************************************************************************************************************/
Board::~Board()
{
	for (int i = 0; i < row; i++)
	{
		delete[] board[i];
	}
	delete[] board;

	board = NULL;
}

/***************************************************************************************************************
** Description: setCell function takes in a character and board array location (i.e. row and column), and sets
** the char element at that specified location in the board with the input character.
***************************************************************************************************************/
void Board::setCell(char inputChar, int selectedRow, int selectedCol)
{
	board[selectedRow-1][selectedCol-1] = inputChar;
}

/***************************************************************************************************************
** Description: getRow returns the row size of the board array.
***************************************************************************************************************/
int Board::getRow()
{
	return row;
}

/***************************************************************************************************************
** Description: getCol returns the column size of the board array.
***************************************************************************************************************/
int Board::getCol()
{
	return col;
}

/***************************************************************************************************************
** Description: getCell returns the char value held at the board array location specified by the functions
** parameter (i.e. row and column).
***************************************************************************************************************/
char Board::getCell(int selectedRow, int selectedCol)
{
	return board[selectedRow-1][selectedCol-1];
}

/***************************************************************************************************************
** Description: displayBoard prints the board array with included row and column number labels.
***************************************************************************************************************/
void Board::displayBoard()
{
	//display top number labels
	cout << "       ";
	for (int i = 0; i < col; i++)
	{
		if (i < 9)
		{
			cout << "0";
		}
		cout << (i + 1) << "  ";
	}
	cout << endl;

	//display array with side number labels
	for (int i = 0; i < row; i++)
	{
		if (i < 9)
		{
			cout << "0";
		}
		cout << (i + 1) << " |   ";
		for (int j = 0; j < col; j++)
		{
			cout << board[i][j] << "   ";
		}
		cout << "|" << endl;
	}
}