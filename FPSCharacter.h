

#pragma once

#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AFPSCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

protected:

	/*
	Initialization of  player input components and its action
	*/
	virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;

	/*UFUNCTION()
	void MoveForward(float Val);

	UFUNCTION()
	void MoveRight(float Val);

	UFUNCTION()
	void Open();*/
};
