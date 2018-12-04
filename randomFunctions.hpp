/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This header file contains various function prototypes for functions that handle the random number generator.
***************************************************************************************************************/

#ifndef RANDOMFUNCTIONS_HPP
#define RANDOMFUNCTIONS_HPP

void setSrand();
int randomNumber(int low, int high);
char randomDirection();
void randomStartAndDirection(int &startingRow, int &startingCol, char &startingFacingDirection, const int userRow, const int userCol);

#endif