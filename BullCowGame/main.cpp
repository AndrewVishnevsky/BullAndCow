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
FText GetValidGuess();
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

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); 
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//print number of bulls and cows

		std::cout << "Bulls= " << BullCowCount.Bulls;
		std::cout << ". Cows= " << BullCowCount.Cows << std::endl;

	}
	
		

	//TODO summarise game
}
void PrintInfo()
{
	//Introduce the game
	
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking off?" << std::endl;
}
FText GetValidGuess() //TODO change to GetValidGuess
{	
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << std::endl;
		std::cout << "Enter your Guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters. \n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << " Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::No_LowerCase:
			std::cout << "Please enter all lowercase letters. \n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);//Keep looping until we get no errors
	return Guess;	
}

bool AskToPlayAgain()
{
	std::cout << "Do you want a play again(y/n)?"<<std::endl;
	FText Responce = "";
	getline(std::cin, Responce);

	
	return (Responce[0] == 'y' || Responce[0] == 'Y');
}
