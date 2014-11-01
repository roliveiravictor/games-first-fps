

#include "AlanThornsBook01.h"
#include "FPSCharacter.h"


AFPSCharacter::AFPSCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent * InputComponent)
{
	/*
	Setup GamePlay Keybinds
	*/
	//InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	//InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	//InputComponent->BindAction("Open", this, &AFPSCharacter::Open);
}

