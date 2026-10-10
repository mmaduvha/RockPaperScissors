
#include <iostream>
#include<iomanip>
#include <list>
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
		while (true){

			string roundPlayer;
			char roundChoice;

			list<string> players;
			list<char> choices;

			players.resize(numPlayers);
			choices.resize(numPlayers);

			for (int i = 0; i < numPlayers; i++) {

				cout << "Player " << i + 1 << ", please enter your choice (rock, paper, or scissors): ";
				cin >> playerChoice;

				if (!game.CheckPlayerChoiceIsPermitted(playerChoice))
				{
					cout << "Invalid choice. Please enter R, P, or S." << endl;
					i--;
				}
				else {
					players.push_back("Player " + to_string(i + 1));
					choices.push_back(playerChoice);
				}
			}

			for (int i = 0; i < players.size(); i++) {

				if (choices[i] == 'R') {//rock beats scissors	
					for (int j = 0; j < players.size(); j++) {
						if (choices[j] == 'S') {
							players[j].erase();
							choices[j] = ' ';

						}
					}
				}

				if (choices[i] == 'P') {//paper beats rock
					for (int j = 0; j < players.size(); j++) {
						if (choices[j] == 'R') {
							players[j].erase();
							choices[j] = ' ';
						}
					}
				}

				if (choices[i] == 'S') {//scissors beats paper
					for (int j = 0; j < players.size(); j++) {
						if (choices[j] == 'P') {
							players[j].erase();
							choices[j] = ' ';
						}
					}
				}

				
			}
			if (choices.size() == 0 && players.size() == 1) {

				//it's a tie

			}

			if (choices.size() == 1 && players.size() == 1) {
				cout << "Player " << players.front() << " wins!" << endl;
				break;
			}

		}

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


