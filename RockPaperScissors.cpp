#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class RockPaperScissorsGame {
public:
	bool CheckPlayerChoiceIsPermitted(char playerChoice)
	{
		if (playerChoice != 'R' && playerChoice != 'P' && playerChoice != 'S' &&
			playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's')
		{
			return false;
		}
		return true;
	}
};

int main()
{
	int numPlayers = 0;
	RockPaperScissorsGame game;

	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "Players can be up to 4." << endl;

	while (true)
	{
		cout << "Please enter the number of the players: ";
		cin >> numPlayers;

		if (numPlayers > 4 || numPlayers < 1)
		{
			cout << "Invalid number of players. Players can only be up to 4. Try Again" << endl;
			continue;
		}

		cout << "[R] for Rock" << endl;
		cout << "[P] for Paper" << endl;
		cout << "[S] for Scissors" << endl;

		char playAgain = 'Y';
		while (playAgain == 'Y' || playAgain == 'y') {
			vector<char> choices(numPlayers);

			for (int i = 0; i < numPlayers; i++) {
				cout << "Player " << i + 1 << ", please enter your choice (R/P/S): ";
				char playerChoice;
				cin >> playerChoice;

				playerChoice = toupper(playerChoice);

				if (game.CheckPlayerChoiceIsPermitted(playerChoice))
				{
					choices[i] = playerChoice;
				}
				else
				{
					cout << "Invalid choice. Please enter R, P, or S." << endl;
					i--;
					continue;
				}
			}

			bool hasRock = false;
			bool hasPaper = false;
			bool hasScissors = false;

			for (char c : choices) {
				if (c == 'R') hasRock = true;
				else if (c == 'P') hasPaper = true;
				else if (c == 'S') hasScissors = true;
			}

			if (hasRock && hasPaper && hasScissors) {
				cout << "It's a tie! All choices were played." << endl;
			}
			else if (hasRock && hasPaper && !hasScissors) {
				cout << "Paper wins!" << endl;
				for (int i = 0; i < numPlayers; i++) {
					if (choices[i] == 'P') {
						cout << "Player " << (i + 1) << " wins!" << endl;
					}
				}
			}
			else if (hasRock && !hasPaper && hasScissors) {
				cout << "Rock wins!" << endl;
				for (int i = 0; i < numPlayers; i++) {
					if (choices[i] == 'R') {
						cout << "Player " << (i + 1) << " wins!" << endl;
					}
				}
			}
			else if (!hasRock && hasPaper && hasScissors) {
				cout << "Scissors wins!" << endl;
				for (int i = 0; i < numPlayers; i++) {
					if (choices[i] == 'S') {
						cout << "Player " << (i + 1) << " wins!" << endl;
					}
				}
			}
			else {
				cout << "It's a tie! All players chose the same." << endl;
			}

			cout << "Would you like to play another round? (Y/N): ";
			cin >> playAgain;
		}

		cout << "Would you like to change the number of players and play again? (Y/N): ";
		char restartChoice;
		cin >> restartChoice;
		if (restartChoice != 'Y' && restartChoice != 'y')
		{
			break;
		}
	}

	return 0;
}