

#include "AlanThornsBook01.h"
#include "MyGameMode.h"
#include "FPSCharacter.h"


AMyGameMode::AMyGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	/*
	Pass created pawn actor to engine's default pawn class
	*/
	DefaultPawnClass = AFPSCharacter::StaticClass();

}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

	/*
	Inform all actors that match is beginning
	*/
	StartMatch();

	if (GEngine)
	{
		/*
		Prints debug message on screen
		*/
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("SURVIVE"));
	}
}
