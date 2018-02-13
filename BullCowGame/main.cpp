#include <iostream>
#include <string>
#include "FBullCowGame.h"


//
void PlayGame();
void PrintInfo();
std::string GetGuess();
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
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop
	//TODO change from FOR to While loop
	for (int count = 0; count < MaxTries; count++)
	{
		std::string Guess = GetGuess(); //TODO make loop checking valid
				
		//submit valid guess to the game
		//print number of bulls and cows
		
		std::cout << "Your guess was: " << Guess<<std::endl;
		std::cout << std::endl;
	}

	//TODO summarise game
}
void PrintInfo()
{
	//Introduce the game
	constexpr int WORD_LENGHT = 5;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGHT << " letter isogram I'm thinking off?" << std::endl;
}
std::string GetGuess()
{	
	int CurrentTry = BCGame.GetCurrentTry() ;
	std::cout << "Try " << CurrentTry << std::endl;
	//Get a guess from player
	std::cout << "Enter your Guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want a play again(y/n)?"<<std::endl;
	std::string Responce = "";
	getline(std::cin, Responce);

	
	return (Responce[0] == 'y' || Responce[0] == 'Y');
}
