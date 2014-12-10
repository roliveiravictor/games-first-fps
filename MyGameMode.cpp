

#include "AlanThornsBook01.h"
#include "MyGameMode.h"
#include "Engine.h"

AMyGameMode::AMyGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	/*	Free view pawn. To use, AFPSCharacter.h needs to included 	*/
	// set default pawn class to our Blueprinted character
	//DefaultPawnClass = AFPSCharacter::StaticClass();
	
	// Imported BP asset 3rdPersonPawn - It will be later converted to 1stPerson
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnObject(TEXT("Blueprint'/Game/Blueprints/BP_FPSCharacter.BP_FPSCharacter'"));
	if (PlayerPawnObject.Object != NULL)
	{
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
	}
}

void AMyGameMode::StartPlay()
{
	Super::StartPlay();
	
	// Inform all actors that match is beginning
	StartMatch();

	if (GEngine)
	{
		// Prints debug message on screen
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("SURVIVE"));
	}
	
}
