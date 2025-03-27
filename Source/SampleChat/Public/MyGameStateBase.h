#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

UCLASS()
class SAMPLECHAT_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AMyGameStateBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextBaseball")
	int32 Turn_Host;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextBaseball")
	int32 Turn_Guest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextBaseball")
	int32 Win_Host;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextBaseball")
	int32 Win_Guest;

	UFUNCTION(BlueprintCallable, Category = "TextBaseball")
	void GameEnd(const FString Winner);
};
