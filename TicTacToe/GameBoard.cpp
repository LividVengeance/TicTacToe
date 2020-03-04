#include <iostream>

using namespace std;

class CGameBoard
{
public:
	CGameBoard();
	~CGameBoard();

	char gameBoard[3][3];


	void PrintPlayBoard(char gameBoard);

	void playPVP();
	bool winCheck(char playerToken);

private:

};

CGameBoard::CGameBoard()
{
}

CGameBoard::~CGameBoard()
{
}

void CGameBoard::PrintPlayBoard(char gameBoard)
{
	/// Prints The Game Board

	system("CLS");
	cout << endl;
	cout << "	,-----------------------------------------,	" << endl;
	cout << "	`-----------------------------------------' " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	  |		[  ]	    [  ]		[  ]    |   " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	  |		[  ]	    [  ]		[  ]    |   " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	  |		[  ]	    [  ]		[  ]    |   " << endl;
	cout << "	  |									    |   " << endl;
	cout << "	,-----------------------------------------,	" << endl;
	cout << "	`-----------------------------------------' " << endl;
	cout << endl;
}

void CGameBoard::playPVP()
{
	bool playerOneTurn = true;

	if (playerOneTurn)
	{

	}
	else
	{

	}
}

bool CGameBoard::winCheck(char playerToken)
{
	char gameBoard[3][3];
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