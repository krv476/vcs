#include <iostream>
#include <iomanip>
#include <errno.h>
#include <signal.h>
#include <string>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <sys/types.h>

const int ROWS = 25;
const int COLUMNS = 51;

void printWelcome();

using namespace std;

int main()
{
	printWelcome();
	char input;

	do
	{
		cout << "Enter command: ";
		cin >> input;
		switch(input)
		{

			case 'q':
			case 'Q':
				cout << "Exiting terminal...\n";
				break;
			case 'h':
			case 'H':
				cout << "Available Commands: ";				//add available commands
				break;
			default:
				cout << "Invalid command! Enter 'H' for help \n";
		}

	}while(input != 'Q');

	cout << "Goodbye, thanks for using my operating system...\n";

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
