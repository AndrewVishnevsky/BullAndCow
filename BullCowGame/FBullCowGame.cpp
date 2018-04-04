#include "FBullCowGame.h"

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
	int32 WorldLenght = MyHiddenWord.length();//assuming same lenght as guess

	for (int32 MHWChar = 0; MHWChar < WorldLenght; MHWChar++)
	{	//Сравниваем буквы с загаданным словом
		for (int32 GChar = 0; GChar < WorldLenght; GChar++)
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
	if (BullCowCount.Bulls == WorldLenght)
	{
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}			
			
	return BullCowCount;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)// if the guess isn't an isogram
	{
		return EWordStatus::Not_Isogram;
	} 
	else if(false) // if the guess isn't all lowercase
		{
		return EWordStatus::No_LowerCase;
		}
		else if (Guess.length()!=GetHiddenWordLength())
		{
			return EWordStatus::Wrong_Length;
		}
			else
			{
				return EWordStatus::OK;
			}

}
