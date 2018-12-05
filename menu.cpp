/**************************************************************************************************************
** Program name: Project 1
** Author: Derrick Li
** Date: Jan. 22, 2017
** Description:
** This implementation file contains definitions for menu-related functions.
***************************************************************************************************************/

#include "menu.hpp"

#include <iostream>
#include <string>	//for string and stoi
#include <cctype>	//for toupper

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;

/***************************************************************************************************************
** Description: inputNumberValidation validates an integer greater than or equal to 1 has been entered. If
** it has, the integer is returned as a reference parameter. If not, a zero is return to its reference parameter.
** The function will only accept whole numbers (0,1,2,3,...,9) and white spaces. It will not accept any
** other characters including decimal points.
***************************************************************************************************************/
void inputNumberValidation(int &num)
{
	num = 0; //initialize a value as default

	string inputString;
	getline(cin, inputString);

	int index = 0;
	bool validNumber = true;

	while (validNumber && index < inputString.length())
	{
		if (!isdigit(inputString[index])&&!isspace(inputString[index]))
		{
			validNumber = false;
		}
		index++;
	}

	if (validNumber && inputString.length() >= 1)
	{
		num = stoi(inputString);
	}

	/*cout << "input: " << inputString << endl;
	cout << "num: " << num << endl;*/
}

/***************************************************************************************************************
** Description: mainMenu will display the main menu and prompt the user to select an option. It also contains
** input validation to ensure the user selects a valid option. A true bool value is returned if the user
** would like to proceed with the simluation. A false bool value is returned if the user wishes to exit.
***************************************************************************************************************/
bool mainMenu()
{
	bool validChoice = false;
	bool play = false;
	int choice;

	system("clear");
	cout << "Welcome to a simple simulation of Langton's Ant." << endl;

	do
	{
		cout << "Please select an option:" << endl;
		cout << "1) Play simulation" << endl;
		cout << "2) Exit" << endl;
		cout << "Choice: ";
		inputNumberValidation(choice);

		if (choice == 1 || choice == 2)
		{
			validChoice = true;

			switch (choice)
			{
			case 1: play = true;
				break;
			case 2: cout << endl << "Goodbye." << endl;
				break;
			}
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl << endl;
		}
	} while (validChoice == false);

	return play;
}

/***************************************************************************************************************
** Description: menuPromptArraySize will prompt the user to enter a valid array size for the board. The number
** of row(s) and column(s) must be 1 or greater. It also contains input validation to ensure the user enters
** valid integers. The values are returned via reference parameters.
***************************************************************************************************************/
void menuPromptArraySize(int &userRow, int &userCol)
{
	bool validRow = false, validCol = false;

	system("clear");
	cout << "We will first need to construct the array." << endl << endl;

	do
	{
		cout << "Please enter an integer value for the number of ROWS you would like to have" << endl;
		cout << "(Integer must be greater than or equal to 1. Suggested range 5 - 20): ";
		inputNumberValidation(userRow);

		if (userRow >= 1)
		{
			validRow = true;
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl << endl;
		}

	} while (validRow == false);

	system("clear");

	do
	{
		cout << "Please enter an integer value for the number of COLUMNS you would like to have" << endl;
		cout << "(Integer must be greater than or equal to 1. Suggested range 5 - 20): ";
		inputNumberValidation(userCol);

		if (userCol >= 1)
		{
			validCol = true;
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl << endl;
		}

	} while (validCol == false);

	system("clear");

	cout << "You've chosen to construct a " << userRow << " x " << userCol << " array." << endl << endl;

}

/***************************************************************************************************************
** Description: menuPromptRandomStartPosition prompts the user if they would like to choose a starting position
** for the ant or allow the program to randomly choose for them. A false bool value is returned if the user
** would like to enter their own values. A true bool value is returned if the user would like the program to
** randomly choose. It also contains input validation to ensure the user selects a valid option.
***************************************************************************************************************/
bool menuPromptRandomStartPosition()
{
	bool validRandChoice = false;
	bool randomStartingPosition;
	int randChoice;

	cout << endl << "Now you will need to decide on the starting position and facing direction of the ant." << endl << endl;

	do
	{
		cout << "Would you like to choose a starting position and facing direction or allow the program to randomly choose for you? " << endl;
		cout << "Enter \"1\" to personally choose or \"2\" to allow the program to randomly choose: ";
		inputNumberValidation(randChoice);

		if (randChoice == 1 || randChoice == 2)
		{
			validRandChoice = true;

			switch (randChoice)
			{
			case 1: randomStartingPosition = false;
				break;
			case 2: randomStartingPosition = true;
				break;
			}
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl << endl;
		}
	} while (validRandChoice == false);

	return randomStartingPosition;
}

/***************************************************************************************************************
** Description: menuPromptStartPosition prompts the user to enter values for the position and facing
** direction they would like the ant to start with. It references the board object row and column values
** to prompt the user with a range and uses it in the input validation to ensure the user
** enters a valid row/column within the array bounds. It also has input validation for the facing direction
** input to ensure the user enters a valid character to represent a corresponding cardinal direction.
***************************************************************************************************************/
void menuPromptStartPosition(int &startingRow, int &startingCol, char &startingFacingDirection, const int userRow, const int userCol)
{
	bool validStartingRow = false, validStartingCol = false, validStartingFacingDirection = false;

	system("clear");

	do
	{
		cout << "Which ROW would you like the ant to start at?" << endl;
		cout << "(Value must be between 1 and " << userRow << "): ";
		inputNumberValidation(startingRow);

		if (startingRow >= 1 && startingRow <= userRow)
		{
			validStartingRow = true;
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl << endl;
		}
	} while (validStartingRow == false);

	system("clear");

	do
	{
		cout << "Which COLUMN would you like the ant to start at?" << endl;
		cout << "(Value must be between 1 and " << userCol << "): ";
		inputNumberValidation(startingCol);

		if (startingCol >= 1 && startingCol <= userCol)
		{
			validStartingCol = true;
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl << endl;
		}
	} while (validStartingCol == false);

	system("clear");

	do
	{
		cout << "Which direction would you like the ant to face?" << endl;
		cout << "(Enter \"N\" for North, \"E\" for East, \"S\" for South, and \"W\" for West): ";
		cin >> startingFacingDirection;
		cin.ignore();	//needed to clear input buffer
		startingFacingDirection = toupper(startingFacingDirection);

		switch (startingFacingDirection)
		{
		case 'N':
		case 'E':
		case 'S':
		case 'W':
			validStartingFacingDirection = true;
			break;
		default:
			cout << endl << "Invalid choice. Try again." << endl << endl;
			break;
		}

	} while (validStartingFacingDirection == false);

	system("clear");

	cout << "You've chosen the ant to start at row " << startingRow << " and column " << startingCol << " facing ";
	cout << directionCharToString(startingFacingDirection) << "." << endl;

}

/***************************************************************************************************************
** Description: menuPromptNumberOfSteps prompts the user to enter the number of step they wish the simulation
** to run up to. It also contains input validation to ensure the user enter a valid integer greater than or
** equal to 1. This integer value is returned from the function.
***************************************************************************************************************/
int menuPromptNumberOfSteps()
{
	bool validChoice = false;
	int chosenNumberOfSteps;

	do
	{
		cout << endl << "How many steps would you like the simulation to make? " << endl;
		cout << "(Enter an integer greater than or equal to 1): ";
		inputNumberValidation(chosenNumberOfSteps);

		if (chosenNumberOfSteps >= 1)
		{
			validChoice = true;
		}
		else
		{
			cout << endl << "Invalid choice. Try again." << endl;
		}

	} while (validChoice == false);

	system("clear");
	cout << "You have chosen to run the simulation for " << chosenNumberOfSteps << " steps." << endl << endl;

	return chosenNumberOfSteps;
}

/***************************************************************************************************************
** Description: directionCharToString takes in a single char representing one of the four cardinal directions and
** converts it to a string so that the cardinal direction is fully spelled out. This string value is returned
** from the function.
***************************************************************************************************************/
string directionCharToString(char startingFacingDirection)
{
	string stringValue;

	switch (startingFacingDirection)
	{
	case 'N': stringValue = "North";
		break;
	case 'E': stringValue = "East";
		break;
	case 'S': stringValue = "South";
		break;
	case 'W': stringValue = "West";
		break;
	}

	return stringValue;
}