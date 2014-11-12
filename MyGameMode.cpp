

#include "AlanThornsBook01.h"
#include "MyGameMode.h"
#include "Engine.h"

AMyGameMode::AMyGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnObject(TEXT("Blueprint'/Game/ExampleContent/AnimationDemo/BluePrints/SimpleAnimationBPCharacter.SimpleAnimationBPCharacter'"));
	if (PlayerPawnObject.Object != NULL)
	{
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
	}
}

void AMyGameMode::StartPlay()
{
	Super::StartPlay();
	
	//Inform all actors that match is beginning
	StartMatch();

	if (GEngine)
	{
		//Prints debug message on screen
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("SURVIVE"));
	}
	
}
