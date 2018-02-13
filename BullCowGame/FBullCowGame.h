#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); //Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string);//TODO make a more rich return value
	void Reset(); //TODO make a more rich return value
	// SomeNewType SubmitValidGuess()

private:
	int MyCurrentTry;
	int MyMaxTries;
	
};