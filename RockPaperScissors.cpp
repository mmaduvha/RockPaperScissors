
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

		cout << "Welcome to Rock, Paper, Scissors!" << endl;
		cout << "Players can be up to 4." << endl;

		cout << "[R] for Rock" << endl;
		cout << "[P] for Paper" << endl;
		cout << "[S] for Scissors" << endl;

		//the beginning ends here, the game will ask the user to enter their choice of rock, paper, or scissors

		//the rounds of the game will continue until the user decides to exit the game,
		// this is the main loop of the game

		while (true) {

			for (int i = 0; i < numPlayers; i++) {
				cout << "Player " << i + 1 << ", please enter your choice (R/P/S): ";
				cin >> playerChoice;

				if (!game.CheckPlayerChoiceIsPermitted(playerChoice))
				{
					cout << "Invalid choice. Please enter R, P, or S." << endl;
					i--; // Decrement i to repeat the current player's turn
					continue;
				}


			}

			break;


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



