

#pragma once

#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AMyGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;
};


