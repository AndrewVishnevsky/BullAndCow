/*
	This acts as the view a MVC pattern, and|
	user interaction. For a game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
//
void PlayGame();
void PrintInfo();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; //New game                                                                                                                                                                  

int main()
{
	bool bPlayAgain = false;
	do 
	{
		PrintInfo();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop
	//TODO change from FOR to While loop
	for (int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetGuess(); //TODO make loop checking valid

		EWordStatus Status = BCGame.CheckGuessValidity(Guess);
				
		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print number of bulls and cows
		std::cout << "Bulls= " << BullCowCount.Bulls;
		std::cout << ". Cows= " << BullCowCount.Cows<<std::endl;
		
	}

	//TODO summarise game
}
void PrintInfo()
{
	//Introduce the game
	
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking off?" << std::endl;
}
FText GetGuess() //TODO change to GetValidGuess
{	
	int32 CurrentTry = BCGame.GetCurrentTry() ;
	std::cout << "Try " << CurrentTry << std::endl;
	//Get a guess from player
	std::cout << "Enter your Guess: ";
	FText Guess = "";
	getline(std::cin, Guess);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want a play again(y/n)?"<<std::endl;
	FText Responce = "";
	getline(std::cin, Responce);

	
	return (Responce[0] == 'y' || Responce[0] == 'Y');
}
