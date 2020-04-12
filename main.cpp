#include <iostream>
#include <iomanip>
#include <errno.h>
#include <signal.h>
#include <string>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#include "lcommands.h"
#include "calc.h"

const int ROWS = 25;
const int COLUMNS = 51;

void printWelcome();

void guessingGame();

using namespace std;

int main()
{
	printWelcome();
	char input;
	Calc calculator;
	string t[8];
	int count;

	do
	{
		cout << "Enter command: ";
		cin >> input;
		switch(input)
		{
			case 'g':
			case 'G':
				guessingGame();
				break;
			case 'l':
			case 'L':
				do
				{
					count = get(t);
				}while(process(t, count));
				break;
			case 'c':
			case 'C':
				cout << "Starting basic calculator...\n";
				while(true)
				{
					cout << "Add(A), subtract(S), multiply(M), divide(D), modulo(R), power(P), root(T), exit(E): ";
					cin >> input;
					if(input == 'A' || input == 'a')
						calculator.add();
					else if(input == 'S' || input == 's')
						calculator.subtract();
					else if(input == 'M' || input == 'm')
						calculator.multiply();
					else if(input == 'D' || input == 'd')
						calculator.divide();
					else if(input == 'R' || input == 'r')
						calculator.mod();
					else if(input == 'P' || input == 'p')
						calculator.power();
					else if(input == 'T' || input == 't')
						calculator.root();
					else if(input == 'E' || input == 'e')
					{
						cout << "Exiting calculator...\n";
						break;
					}
					else
					{
						cout << "Invalid command, try again..\n";
						continue;
					}
				}
				break;
			case 'h':
			case 'H':
				cout << "Available Commands: Quit(Q), Calculator(C), linux commands(L), Help(H), Guessing game(G) ...\n";				//add available commands
				break;
			default:
				cout << "Invalid command! Enter 'H' for help \n";
			case 'q':
			case 'Q':
				cout << "Exiting terminal...\n";
				cout << "Goodbye, thanks for using my terminal...\n";
				return 1;
		}

	}while(input != 'q' || input != 'Q');

	return 0;
}


void printWelcome()
{
	char message[][COLUMNS] = {{"##################################################"},
			  {"###   ##############     ###################   ###"},
			  {"###   #############   #   #################   ####"},
			  {"###   ############   ###   ###############   #####"},
			  {"###   ###########   #####   #############   ######"},
			  {"###   ##########   #######   ###########   #######"},
			  {"###   #########   #########   #########   ########"},
			  {"###   #######   ############   #######   #########"},
			  {"###   ######   ##############   #####   ##########"},
			  {"###   ####   #################   ###   ###########"},
			  {"###   ###  ####################   #   ############"},
			  {"###   #   #######################   ##############"},
			  {"###     ##########################################"},
			  {"###      ##############                       ####"},
			  {"###   #   #######################   ##############"},
			  {"###   ##   ######################   ##############"},
			  {"###   ###   #####################   ##############"},
			  {"###   ####   ####################   ##############"},
			  {"###   #####   ###################   ##############"},
			  {"###   ######   ##################   ##############"},
			  {"###   #######   #################   ##############"},
			  {"###   ########   ################   ##############"},
			  {"###   ##########   ##############   ##############"},
			  {"###   ###########   #############   ##############"},
			  {"##################################################"}};

	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLUMNS; j++)
		{
			cout << message[i][j];
			nanosleep((const struct timespec[]){{0, 500000L}}, NULL);
		}
		cout << endl;
	}
}

void guessingGame()
{
	srand(time(NULL));
	int randomnumber, score = 0, guess;

	cout << "Try to guess the number 10 times!\n";

	for(int i = 0; i < 10; i++)
	{
		randomnumber = rand() % 10;
		cout << "Pick a number between 0-9: ";
		cin >> guess;

		if(guess == randomnumber)
		{
			score += 10;
			cout << "You guessed right! You have " << score << " points! \n";
		}
		else
			cout << "Wrong number!\n";
	}

	if(score == 100)
	{
		cout << "Wow! You got all of them right! Amazing!\n";
	}
	else
		cout << "You got " << score << " total points!\n";

	cout << "Thanks for playing!\n";
}