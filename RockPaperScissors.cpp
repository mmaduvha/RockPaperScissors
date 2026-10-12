
#include <iostream>
#include<iomanip>
#include <list>
#include <vector>
#include <string>

using namespace std;

class RockPaperScissorsGame {

public:
	bool CheckPlayerChoiceIsPermitted(char playerChoice)
	{
		enum class PermittedChoices : char {
			Rock = 'R',
			Paper = 'P',
			Scissors = 'S'
		};
		if (playerChoice != static_cast<char>(PermittedChoices::Rock) &&
			playerChoice != static_cast<char>(PermittedChoices::Paper) &&
			playerChoice != static_cast<char>(PermittedChoices::Scissors))
		{
			return false;

		}
		return true;


	}

public:
	void DetermineWinner() {
		while (true) {
			int numPlayers;

			vector<string> players;
			vector<char> choices;

			for (int i = 0; i < numPlayers; i++) {
				char roundChoice;
				cout << "Player " << i + 1 << ", please enter your choice (R, P, or S): ";
				cin >> roundChoice;

				if (!CheckPlayerChoiceIsPermitted(roundChoice)) {
					cout << "Invalid choice. Please enter R, P, or S." << endl;
					i--;
				}
				else {
					players.push_back("Player " + to_string(i + 1));
					choices.push_back(roundChoice);
				}
			}

			vector<bool> eliminated(players.size(), false);

			for (size_t i = 0; i < players.size(); i++) {
				if (choices[i] == 'R') {
					for (size_t j = 0; j < players.size(); j++) {
						if (choices[j] == 'S') {
							eliminated[j] = true;
						}
					}
				}

				if (choices[i] == 'P') {
					for (size_t j = 0; j < players.size(); j++) {
						if (choices[j] == 'R') {
							eliminated[j] = true;
						}
					}
				}

				if (choices[i] == 'S') {
					for (size_t j = 0; j < players.size(); j++) {
						if (choices[j] == 'P') {
							eliminated[j] = true;
						}
					}
				}
			}

			vector<string> activePlayers;
			vector<char> activeChoices;
			for (size_t i = 0; i < players.size(); i++) {
				if (!eliminated[i]) {
					activePlayers.push_back(players[i]);
					activeChoices.push_back(choices[i]);
				}
			}

			bool allSame = true;
			if (!activeChoices.empty()) {
				char first = activeChoices[0];
				for (char c : activeChoices) {
					if (c != first) {
						allSame = false;
						break;
					}
				}
			}

			if (activePlayers.size() == 1) {
				cout << activePlayers[0] << " wins!" << endl;
				break;
			}
			else if (activePlayers.empty() || allSame) {
				cout << "It's a tie! Let's play another round." << endl;
			}
			else {
				numPlayers = activePlayers.size();
			}
		}
	};
};

int main()
{

	int numPlayers = 0;
	char playerChoice;

	RockPaperScissorsGame game;

	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "Players can be up to 4." << endl;

	while (true)
	{
		cout << "Please enter the number of the players: ";//the beginning of the game, 
		//ask the user how many players will be playing
		cin >> numPlayers;

		if (numPlayers > 4 || numPlayers < 1)
		{
			cout << "Invalid number of players. Players can only be up to 4. Try Again" << endl;
			continue;
		}

		cout << "[R] for Rock" << endl;
		cout << "[P] for Paper" << endl;
		cout << "[S] for Scissors" << endl;

		//the beginning ends here, the game will ask the user to enter their choice of rock, paper, or scissors

		//the rounds of the game will continue until the user decides to exit the game,
		// this is the main loop of the game

		game.DetermineWinner();

		// rentry or exit point
		cout << "Would you like to play again? (Y/N): ";//ask the user if they want to play again
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			continue;
		}
		else
			break;
	}

}



