/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This header file contains various function prototypes for the menu-related functions.
***************************************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

void inputNumberValidation(int &num);

bool mainMenu();
void menuPromptArraySize(int &userRow, int &userCol);
bool menuPromptRandomStartPosition();
void menuPromptStartPosition(int &startingRow, int &startingCol, char &startingFacingDirection, const int userRow, const int userCol);
int menuPromptNumberOfSteps();

string directionCharToString(char startingFacingDirection);

#endif