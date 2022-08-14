// Shjon Oelke
// Header and source project

#include <iostream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

void gameBoard() {
	cout << "Player1 is X,Player2 is O" << endl;
	cout << "     |      |    " << endl;
	cout << " " << board[0][0] << "  | " << board[0][1] << "  | " << board[0][2] << endl;
	cout << "-----|------|----" << endl;
	cout << " " << board[1][0] << "  | " << board[1][1] << "  | " << board[1][2] << endl;
	cout << "-----|------|----" << endl;
	cout << " " << board[2][0] << "  | " << board[2][1] << "  | " << board[2][2] << endl;
	cout << "     |      |    " << endl;
}

void playerTurn() {
	if (turn == 'x') {
		cout << "player1, it is your turn:  " << endl;
	}
	else {
		cout << "player2, it is yout turn:  " << endl;
	}
	cin >> playerChoice;

	switch (playerChoice) {
	case 1: rows = 0; columns = 0; break;
	case 2: rows = 0; columns = 1; break; 
	case 3: rows = 0; columns = 2; break;
	case 4: rows = 1; columns = 0; break;
	case 5: rows = 1; columns = 1; break;
	case 6: rows = 1; columns = 2; break;
	case 7: rows = 2; columns = 0; break;
	case 8: rows = 2; columns = 1; break;
	case 9: rows = 2; columns = 2; break;
	default:
		cout << "That move is invalid" << endl;
	}
	if (turn = 'X' && board[rows][columns] != 'x' && board[rows][columns] != 'O'){
		board[rows][columns] = 'o';
			turn = 'x';
	}
	else if (turn = 'X' && board[rows][columns] != 'x' && board[rows][columns] != 'O') {
		board[rows][columns] = 'x';
		turn = 'o';
	}
	else {
		cout << "That spot is taken. Please select another spot for your turn" << endl;
			playerTurn();
	}

	gameBoard();
}

bool gameover() {
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'x' && board[i][j] != 'o')
				return true;

	draw = true;
	return false;
}

int main()
{
	cout << " Welcome to a game of TikTakToe! " << endl;
	while (gameover()) {
		gameBoard();
		playerTurn();
		gameover();
	}
	if (turn == 'x' && draw == false) {
		cout << "Congrats! Player1 has won the game! " << endl;
	}
	else if (turn == 'o' && draw == false) {
		cout << "Congrats! player2 has won the game!" << endl;
	}
	else
	{
		cout << " the game has ended in a draw." << endl;
	}

}
 
