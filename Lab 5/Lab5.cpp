/*
	Tait Whitten
	C++ Fall 2019
	Due: 10/24/2019
	Lab 5: Number Guessing Game
	Create a number guessing game that generates a number between 0 and 100 that the player has 20 guesses to guess. After they win or
	they use all their guesses they should be presented with 1 of 10 different win or loss statements, followed by 1 of 10 different 'play
	again?' questions. After the user is done playing the program should output the total number of wins and losses.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void winner() //function for winning the game
{
	srand(time(NULL));
	int randWin = rand() % 10 + 1; //generates a random number between 1 and 10
	switch (randWin)
	{
	case 1:
		cout << "You win" << endl;
		break;
	case 2:
		cout << "Winner winner chicken dinner" << endl;
		break;
	case 3:
		cout << "Congratulations" << endl;
		break;
	case 4:
		cout << "You guessed correctly" << endl;
		break;
	case 5:
		cout << "You're right" << endl;
	case 6:
		cout << "Nice answer" << endl;
		break;
	case 7:
		cout << "You actually got it right?" << endl;
		break;
	case 8:
		cout << "Good job, that was correct" << endl;
		break;
	case 9:
		cout << "Fantastic work" << endl;
		break;
	case 10:
		cout << "Winner" << endl;
		break;
	}
}

void loser() //function for losing the game
{
	srand(time(NULL));
	int randLoss = rand() % 10 + 1; //generates a random number between 1 and 10
	switch (randLoss)
	{
	case 1:
		cout << "You lose, loser" << endl;
		break;
	case 2:
		cout << "You didn't guess the right number" << endl;
		break;
	case 3:
		cout << "You ran out of guesses" << endl;
		break;
	case 4:
		cout << "If you were trying to lose you did well" << endl;
		break;
	case 5:
		cout << "You suck" << endl;
	case 6:
		cout << "Maybe if you didn't suck you would've won" << endl;
		break;
	case 7:
		cout << "Try not sucking next time" << endl;
		break;
	case 8:
		cout << "Better luck next time" << endl;
		break;
	case 9:
		cout << "That was a terrible effort" << endl;
		break;
	case 10:
		cout << "Unlucky" << endl;
		break;
	}
}

void again() //function for playing the game again 
{
	srand(time(NULL));
	int randAgain = rand() % 10 + 1; //generates a random number between 1 and 10
	switch (randAgain)
	{
	case 1:
		cout << "Do you want to play again? ";
		break;
	case 2:
		cout << "Wanna play again? ";
		break;
	case 3:
		cout << "That was fun. Play again? ";
		break;
	case 4:
		cout << "You have nothing better to do. Play again? ";
		break;
	case 5:
		cout << "Are you going to play another game? ";
	case 6:
		cout << "Time to play another game? ";
		break;
	case 7:
		cout << "Are you playing again? ";
		break;
	case 8:
		cout << "Lets play another round? ";
		break;
	case 9:
		cout << "You can win more if you play again. ";
		break;
	case 10:
		cout << "More games = more fun. Play again? ";
		break;
	}
}

int main()
{
	//variable declaration
	bool play;
	int input;
	int answer;
	int i;
	int r1;
	int wins = 0;
	int losses = 0;

	do
	{
		
		cout << "Welcome to the number guessing game." << endl << "Please enter a number between 0 and 100: ";
		srand(time(NULL)); //makes the random number psuedo random
		r1 = rand() % 101; // generates a random number between 0 and 100
		for (i = 1; i <= 19; i++) //loops for the first 19 guesses
		{
			cin >> input;
			
			if (input == r1) {
				winner(); //function call for the outputted winning statement
				break;
			}
			else
				cout << "Guess again: ";
		}
		
		if (i = 20 && input != r1) { //if statement for the last guess so it doesn't say guess again after
			cin >> input;
			if (input == r1)
				cout << "You won!" << endl;
			else 
				loser(); //function call for the outputted losing statement

		}

		cout << "Correct answer: " << r1 << endl; //outputs the random number that the player was attempting to guess
		
		if (r1 == input)
			wins++; //Increases the win counter by 1 if the player won
		if (r1 != input)
			losses++; //Increases the losses counter by 1 if the player loses
		
		again(); //function call for asking the player if they want to play again
		cout << "Enter 1 for yes and 2 for no" << endl; //adds instructions to the end of the play again question for the user
		cin >> answer;

		if (answer == 1)
			play = true; //keeps play true so the do-while loop repeats
		else if (answer == 2)
			play = false; //sets play to false so the do-while loop does not repeat
		else {
			cout << "Invalid input, ending the program" << endl;
			play = false; //sets play to false so the do-while loop does not repeat
		}
	} while (play);

	cout << "Thank you for playing" << endl;

	cout << "Wins: " << wins << endl; //outputs the players total number of wins
	cout << "Losses: " << losses << endl; //outputs the players total number of losses

	return 0;
}

