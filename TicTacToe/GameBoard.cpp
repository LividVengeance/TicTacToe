#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

class CGameBoard
{
public:
	CGameBoard();
	~CGameBoard();

	char gameBoard[3][3];

	void PrintPlayBoard();
	char CreateBoard();
	void playPVP();
	void playPVEasy();
	bool CheckBoard(int row, int column, char playerToken);
	bool winCheck(char playerToken);

private:

};

CGameBoard::CGameBoard()
{
}

CGameBoard::~CGameBoard()
{
}

char CGameBoard::CreateBoard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gameBoard[i][j] = '-';
		}
	}
	return(gameBoard[3][3]);
}

void CGameBoard::PrintPlayBoard()
{
	/// Prints The Game Board
	system("CLS");
	cout << endl;
	cout << "	,-----------------------------------------,	" << endl;
	cout << "	`-----------------------------------------' " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	  |		[ " << gameBoard[0][0] << " ]	    [ " << gameBoard[0][1] << " ]		[ " << gameBoard[0][2] << " ]    |   " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	  |		[ " << gameBoard[1][0] << " ]	    [ " << gameBoard[1][1] << " ]		[ " << gameBoard[1][2] << " ]    |   " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	  |		[ " << gameBoard[2][0] << " ]	    [ " << gameBoard[2][1] << " ]		[ " << gameBoard[2][2] << " ]    |   " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	,-----------------------------------------,	" << endl;
	cout << "	`-----------------------------------------' " << endl;
	cout << endl;
}

void CGameBoard::playPVP()
{
	bool playerOneTurn = true;
	bool notWon = true;
	
	while (notWon)
	{
		if (playerOneTurn)
		{
			//  Asks player one for place location
			cout << "Please enter the row you would like to place" << endl;
			char playerOneRow;
			cin >> playerOneRow;
			cout << "Please enter the column you would like to place" << endl;
			char playerOneCol;
			cin >> playerOneCol;

			// Checks to see if can place at location
			if (CheckBoard(playerOneRow, playerOneCol, 'X') == false)
			{
				cout << "Please enter a vaild location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(10000, '\n');
				playPVP();
			}

			// Checks to see if player one has won
			if (winCheck('X'))
			{
				cout << "Player One Wins" << endl;
			}

			// Clears inputs for next round
			cin.clear();
			cin.ignore(10000, '\n');
			playerOneTurn = false;
		} 
		else
		{
			//  Asks player two for place location
			cout << "Please enter the row you would like to place" << endl;
			char playerTwoRow;
			cin >> playerTwoRow;
			cout << "Please enter the column you would like to place" << endl;
			char playerCol;
			cin >> playerCol;

			// Checks to see if can place at location
			if (CheckBoard(playerTwoRow, playerCol, 'O') == false)
			{
				cout << "Please enter a vaild location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(10000, '\n');
				playPVP();
			}

			// Checks to see if player two has won
			if (winCheck('O'))
			{
				cout << "Player Two Wins" << endl;
			}

			// Clears inputs for next round
			cin.clear();
			cin.ignore(10000, '\n');
			playerOneTurn = true;
		}
	}
}

void CGameBoard::playPVEasy()
{
	bool notWon = true;
	bool playerTurn = true;

	while (notWon)
	{
		if (playerTurn)
		{
			//  Asks players for place location
			cout << "Please enter the row you would like to place" << endl;
			char playerRow;
			cin >> playerRow;
			cout << "Please enter the column you would like to place" << endl;
			char playerCol;
			cin >> playerCol;

			// Checks to see if can place at location
			if (CheckBoard(playerRow, playerCol, 'X') == false)
			{
				cout << "Please enter a vaild location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(10000, '\n');
				playPVP();
			}

			// Checks to see if player has won
			if (winCheck('X'))
			{
				cout << "User Wins" << endl;
				Sleep(1000);
			}
			playerTurn = false;
		}
		else
		{
			bool notPlaced = true;

			// Gets random location on board
			int randRow = rand() % 4;
			int randCol = rand() % 4;

			// Checks to see if can place at location
			while (notPlaced)
			{
				// Gets random location on board
				int randRow = rand() % 4;
				int randCol = rand() % 4;

				if (CheckBoard(randRow, randCol, 'O'))
				{
					notPlaced = false;
				}
			}

			// Checks to see if computer won
			if (winCheck('O'))
			{
				cout << "Computer Wins" << endl;
				Sleep(1000);
			}
			playerTurn = true;

			// Reset for next round
			notPlaced = true;
		}
	}
}

bool CGameBoard::CheckBoard(int row, int column, char playerToken)
{
	bool ablePlaced;

	if (gameBoard[row][column] != '-')
	{
		ablePlaced = false;
	}
	else
	{
		gameBoard[row][column] = playerToken;
		ablePlaced = true;
	}
	return(ablePlaced);
}

bool CGameBoard::winCheck(char playerToken)
{
	bool playerWon;
	
	// Checks for wins on the horizontal
	if (gameBoard[0][0] && gameBoard[0][1] && gameBoard[0][2] == playerToken)
	{
		playerWon = true;
	}
	else if (gameBoard[1][0] && gameBoard[1][1] && gameBoard[1][2] == playerToken)
	{
		playerWon = true;
	}
	else if (gameBoard[2][0] && gameBoard[2][1] && gameBoard[2][2] == playerToken)
	{
		playerWon = true;
	}
	// Checks for wins on the vertical
	if (gameBoard[0][0] && gameBoard[1][0] && gameBoard[2][0] == playerToken)
	{
		playerWon = true;
	}
	else if (gameBoard[0][1] && gameBoard[1][1] && gameBoard[2][1] == playerToken)
	{
		playerWon = true;
	}
	else if (gameBoard[0][2] && gameBoard[1][2] && gameBoard[2][2] == playerToken)
	{
		playerWon = true;
	}
	// Checks for Wins on the diagonal
	else if (gameBoard[0][0] && gameBoard[1][1] && gameBoard[2][2] == playerToken)
	{
		playerWon = true;
	}
	else if (gameBoard[0][2] && gameBoard[1][1] && gameBoard[2][0] == playerToken)
	{
		playerWon = true;
	}
	else
	{
		playerWon = false;
	}
	return (playerWon);
}