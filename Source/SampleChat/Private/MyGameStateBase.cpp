// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase()
{
	Turn_Host = 0;
	Turn_Guest = 0;
	Win_Host = 0;
	Win_Guest = 0;
}

void AMyGameStateBase::GameEnd(const FString Winner)
{
	if (Winner == "Host")
	{
		Win_Host++;
	}
	else
	{
		Win_Guest++;
	}
	Turn_Host = 0;
	Turn_Guest = 0;
}



