#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return false; }




void FBullCowGame::Reset()
{	
	constexpr int MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;	
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//receives a Valid guess, incriments and return
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;

	// ���� �������� ���� �������� � �������� �����
	int32 HiddenWorldLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWorldLenght; MHWChar++)
	{	//���������� ����� � ���������� ������
		for (int32 GChar = 0; GChar < HiddenWorldLenght; GChar++)
		{	//���� ��� ��������� ��
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar==GChar)
				{
					BullCowCount.Bulls++;//����������� ����� ���� ��� � ������ �����
				}
					else
					{//���������� �����
						BullCowCount.Cows++;
					}

			}
		}
	}
		
			
				
						
				//����
					//����������� �����

	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(std::string) const
{
	return false;
}
