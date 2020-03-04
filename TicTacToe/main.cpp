#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;


void playMenu()
{
	/// Displays the play menu
	system("CLS");

	cout << endl;
	cout << "	,--,--'    ,--,--'      ,--,--'      " << endl;
	cout << "	`- | . ,-. `- | ,-. ,-. `- | ,-. ,-. " << endl;
	cout << "	 , | | |    , | ,-| |    , | | | |-' " << endl;
	cout << "	 `-' ' `-'  `-' `-^ `-'  `-' `-' `-' " << endl;
	cout << endl << endl;
	cout << "		1. Easy" << endl;
	cout << endl;
	cout << "		2. Hard" << endl;
	cout << endl;
	cout << "		3. Player Vs Player" << endl;
	cout << endl;
	cout << "		4. Back to Main Menu" << endl;
	cout << endl;

	int Option;
	cin >> Option;

	if (Option == 1)
	{
		playMenu();
	}
	else if (Option == 2)
	{
		system("exit");
	}
	else if (Option == 3)
	{
		system("exit");
	}
	else if (Option == 4)
	{
		
	}
	else
	{
		system("CLS");
		cout << endl << endl << "		Please Enter A Vaild Input" << endl;
		Sleep(1000);
		cin.clear();
		cin.ignore(10000, '\n');
		playMenu();
	}
}

void mainMenu()
{
	/// Displays the main menu
	system("CLS");

	cout << endl;
	cout << "	,--,--'    ,--,--'      ,--,--'      " << endl;
	cout << "	`- | . ,-. `- | ,-. ,-. `- | ,-. ,-. " << endl;
	cout << "	 , | | |    , | ,-| |    , | | | |-' " << endl;
	cout << "	 `-' ' `-'  `-' `-^ `-'  `-' `-' `-' " << endl;
	cout << endl;

	cout << endl;
	cout << "		1. Play" << endl;
	cout << endl;
	cout << "		2. Quit" << endl;
	cout << endl;

	int Option;
	cin >> Option;

	if (Option == 1)
	{
		playMenu();

	}
	else if (Option == 2)
	{
		system("exit");
	}
	else
	{
		system("CLS");
		cout << endl << endl << "		Please Enter A Vaild Input" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		Sleep(1000);
		mainMenu();
	}
}

int main()
{
	mainMenu();

	return(0);
}