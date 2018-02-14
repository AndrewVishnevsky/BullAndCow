#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){Reset();}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset()
{	
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//receives a Valid guess, incriments and return
	MyCurrentTry++;
	//setup a return variable
	BullCowCount BullCowCount;

	// loop through all letters in the guess
		//compare letters against the hidden word
	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
