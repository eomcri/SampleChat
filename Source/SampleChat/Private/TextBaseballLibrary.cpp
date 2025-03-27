#include "TextBaseballLibrary.h"
#include "MyGameStateBase.h"

// FString UTextBaseballLibrary::GetMyFirstCPP()
// {
// 	return FString(TEXT("Hello CPP lib in BP"));
// }

FString UTextBaseballLibrary::GetNameOrText(const FString Message, const int32 Index)
{
	FString PlayerName, PlayerText;
	if (Message.Split(TEXT(":"), &PlayerName, &PlayerText))
	{
		if (Index == 0)
		{
			return PlayerName;
		}
		return PlayerText;
	}
	return TEXT("ERROR");
}

bool UTextBaseballLibrary::IsTextBaseballPattern(const FString InputText)
{
	if (InputText[0] == '/')
	{
		return true;
	}
	return false;
}

bool UTextBaseballLibrary::IsOut(const FString InputText)
{
	if (InputText.Len() != 4)
	{
		return true;
	}
	if (InputText[1] == InputText[2] || InputText[1] == InputText[3] || InputText[2] == InputText[3])
	{
		return true;
	}
	return false;
}

FString UTextBaseballLibrary::GetStrikeAndBall(const bool IsOut, const FString PlayerName, const FString InputNumber, const FString TargetNumber, AMyGameStateBase* MyGameStateBase)
{
	if (IsOut)
	{
		return TEXT("OUT");
	}
	
	if (PlayerName == TEXT("Host"))
	{
		if (MyGameStateBase->Turn_Host == 3)
		{
			return FString::Printf(TEXT("%s already tried 3 times"), *PlayerName);
		}
		MyGameStateBase->Turn_Host++;
	}
	else
	{
		if (MyGameStateBase->Turn_Guest == 3)
		{
			return FString::Printf(TEXT("%s already tried 3 times"), *PlayerName);
		}
		MyGameStateBase->Turn_Guest++;
	}
	UE_LOG(LogTemp, Display, TEXT("Host: %d"), MyGameStateBase->Turn_Host);
	UE_LOG(LogTemp, Display, TEXT("Guest: %d"), MyGameStateBase->Turn_Guest);
	
	int StrikeCnt = 0, BallCnt = 0;
	// Strike 판단
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			const char Digit_Target = TargetNumber[j];
			if (const char Digit_Input = InputNumber[i]; Digit_Target == Digit_Input)
			{
				if (i == j)
				{
					StrikeCnt++;
				}
				else
				{
					BallCnt++;
				}
			}
		}
	}

	if (StrikeCnt + BallCnt == 0)
	{
		return TEXT("OUT");
	}
	return FString::Printf(TEXT("%dS%dB"), StrikeCnt, BallCnt);
}


FString UTextBaseballLibrary::MakeRandomNumber()
{
	TArray<int32> Numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	FString RandomNumber = "";
	// 배열 섞기
	for (int32 i = Numbers.Num() - 1; i > 1; i--)
	{
		const int32 RandomIndex = FMath::RandRange(0, i-1);
		Numbers.Swap(i,RandomIndex);
	}
	// 숫자 앞 세자리로 리턴
	return FString::Printf(TEXT("%d%d%d"), Numbers[0], Numbers[1], Numbers[2]);
}

FString UTextBaseballLibrary::GameResult(AMyGameStateBase* MyGameStateBase, const FString PlayerName, const FString PlayerResult)
{
	if (MyGameStateBase)
	{
		if (PlayerResult.Contains(TEXT("3S0B")))
		{
			return PlayerName;
		}
		if (PlayerResult.Contains(TEXT("OUT")))
		{
			if (PlayerName == TEXT("Host"))
			{
				return "Guest";
			}
			return "Host";
		}
		
		if (MyGameStateBase->Turn_Host == 3 && MyGameStateBase->Turn_Guest == 3)
		{
			return TEXT("Draw!");
		}
		return TEXT("Playing");
		
	}
	return TEXT("ERROR");
}

FString UTextBaseballLibrary::PrintGameResult(const FString Result)
{
	if (Result == TEXT("Draw!"))
		return Result;
	return FString::Printf(TEXT("%s Win!"), *Result);
}

void UTextBaseballLibrary::ResetGame(AMyGameStateBase* MyGameStateBase)
{
	if (MyGameStateBase)
	{
		MyGameStateBase->Turn_Host = 0;
		MyGameStateBase->Turn_Guest = 0;
	}
}


