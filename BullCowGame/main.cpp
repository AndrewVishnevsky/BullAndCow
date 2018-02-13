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
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop
	
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess<<std::endl;
		std::cout << std::endl;
	}
}
void PrintInfo()
{
	//Introduce the game
	constexpr int WORLD_LENGHT = 5;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking off?" << std::endl;
}
std::string GetGuess()
{	
	int CurrentTry;
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
