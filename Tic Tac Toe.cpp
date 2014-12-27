#include <iostream>
using namespace std;

char grid[10] = {'o','1','2','3','4','5','6','7','8','9'};
int turn = 1;

class Player
{
	public:
		Player();
		int playerMove();
		int getPlayer();
		void changePlayer();

	private:
		int m_player;
		int m_move;
}p;

class Board
{
	public:
		Board();
		bool checkWinner();
		void drawGrid();
		void play();
		bool markGrid(int choice);
	private:
		char m_mark;
}b;

void gameOver();

int main()
{
	while(!b.checkWinner() && turn < 10)
		b.play();

	//Declare winner
	gameOver();
}

Player::Player()
{
	m_player = 1;		//X player always goes first and gets 5 moves. O player will go second and get 4 moves.
}

int Player::playerMove()
{
	cout << "Player " << m_player << ", enter a number:  ";
	cin >> m_move;

	return m_move;
}

int Player::getPlayer()
{
	return m_player;
}

void Player::changePlayer()
{
	if (turn % 2 == 0)
		m_player++;
	else
		m_player--;
}

Board::Board()
{}

bool Board::checkWinner()
{
	//Check for three in a row either vertically, horizontally, or diagonally
	if (grid[1] == grid[2] && grid[2] == grid[3])
		return true;
	else if (grid[4] == grid[5] && grid[5] == grid[6])
		return true;
	else if (grid[7] == grid[8] && grid[8] == grid[9])
		return true;
	else if (grid[1] == grid[4] && grid[4] == grid[7])
		return true;
	else if (grid[2] == grid[5] && grid[5] == grid[8])
		return true;
	else if (grid[3] == grid[6] && grid[6] == grid[9])
		return true;
	else if (grid[1] == grid[5] && grid[5] == grid[9])
		return true;
	else if (grid[3] == grid[5] && grid[5] == grid[7])
		return true;
	else
		return false;
}

void Board::play()
{
	drawGrid();
	m_mark = (p.getPlayer() == 1) ? 'X' : 'O';
	b.markGrid(p.playerMove());
}

void Board::drawGrid()
{
	system("cls");		//Clears the screen from the previous turn

	//Draw the board
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X) - Player 2 (O)\n\n\n";

	cout << "     |     |     \n";
	cout << "  " << grid[1] << "  |  " << grid[2] << "  |  " << grid[3] << "\n";

	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";

	cout << "  " << grid[4] << "  |  " << grid[5] << "  |  " << grid[6] << "\n";

	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";

	cout << "  " << grid[7] << "  |  " << grid[8] << "  |  " << grid[9] << "\n";

	cout << "     |     |     \n\n";
}

bool Board::markGrid(int choice)
{
	//Mark the move on the grid
		if (choice == 1 && grid[1] == '1')
			grid[1] = m_mark;
		else if (choice == 2 && grid[2] == '2')
			grid[2] = m_mark;
		else if (choice == 3 && grid[3] == '3')
			grid[3] = m_mark;
		else if (choice == 4 && grid[4] == '4')
			grid[4] = m_mark;
		else if (choice == 5 && grid[5] == '5')
			grid[5] = m_mark;
		else if (choice == 6 && grid[6] == '6')
			grid[6] = m_mark;
		else if (choice == 7 && grid[7] == '7')
			grid[7] = m_mark;
		else if (choice == 8 && grid[8] == '8')
			grid[8] = m_mark;
		else if (choice == 9 && grid[9] == '9')
			grid[9] = m_mark;
		else
			return false;

		//Update the turn and change the player if the move was successful
		turn++;
		p.changePlayer();

		return true;
}

void gameOver()
{
	b.drawGrid();		//Display results

	//Check who won the game, or if there is a tie
	if (b.checkWinner() && p.getPlayer() - 1 == 1)
		cout << "Player 1 wins!\n";
	else if (b.checkWinner() && p.getPlayer() - 1 == 0)
		cout << "Player 2 wins!\n";
	else
		cout << "Game is a draw.\n";
}