#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame(){Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }




void FBullCowGame::Reset()
{	
	constexpr int MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//receives a Valid guess, incriments and return
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// цикл проверки всех символов в веденном слове
	int32 WordLength = MyHiddenWord.length();//assuming same lenght as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{	//Сравниваем буквы с загаданным словом
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{	//Если они совпадают то
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar==GChar)
				{
					BullCowCount.Bulls++;//увеличиваем быков если они в нужном месте
				}
					else
					{//увеличивем коров
						BullCowCount.Cows++;
					}

			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}			
			
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString) const
{
	//treat 0 and 1 letter words as isograms
		//if the letter is in the map
			//we do NOT have an isogram
		//otherwise
			//add the letter to the map as seen
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if(false) // if the guess isn't all lowercase
		{
		return EGuessStatus::No_LowerCase;
		}
		else if (Guess.length()!=GetHiddenWordLength())
		{
			return EGuessStatus::Wrong_Length;
		}
			else
			{
				return EGuessStatus::OK;
			}

}
