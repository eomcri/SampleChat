#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextBaseballLibrary.generated.h"

class AMyGameStateBase;


UCLASS()
class SAMPLECHAT_API UTextBaseballLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// UFUNCTION(BlueprintCallable, Category = "TestCode")
	// static FString GetMyFirstCPP();

	// 입력을 플레이어 이름과 텍스트로 분리하는 함수
	// 리턴 값 TArray<FString>
	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static FString GetNameOrText(FString Message, int32 Index);
	

	// 응답 패턴인지 조사하는 함수
	// '/로 시작해야함'
	// 리턴 값 bool
	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static bool IsTextBaseballPattern(FString InputText);

	// Out 판단 함수 (GetStrikeAndBall 함수 안에서 사용)
	// 아웃 조건 1. 중복된 숫자를 사용하였을 때
	// 아웃 조건 2. 숫자가 3개가 아닐 경우
	// 리턴 값 bool
	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static bool IsOut(FString InputText);

	// Strike Ball 개수 판단
	// 자리와 숫자가 같으면 Strike 다르면 Ball
	// 1S2B와 같은 형식으로 리턴
	// Strike와 Ball이 0이면 Out 리턴
	// 리턴 값 FString
	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static FString GetStrikeAndBall(bool IsOut, FString PlayerName, FString InputNumber, FString TargetNumber, AMyGameStateBase* MyGameStateBase);

	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static FString MakeRandomNumber();

	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static FString GameResult(AMyGameStateBase* MyGameStateBase, const FString PlayerName, FString PlayerResult);
	
	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static FString PrintGameResult(const FString Result);

	// 게임 리셋
	// 게임 스테이트 Turn 0으로 초기화
	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	static void ResetGame(AMyGameStateBase* MyGameStateBase);
};
