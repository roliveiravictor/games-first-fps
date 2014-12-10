

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

	// Initialization of  player input components and its action
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<UCameraComponent> FirstPersonCameraComponent;

	// 1st person mesh Arms seen only by self
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	TSubobjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	UFUNCTION()
	void MoveForward(float val);

	UFUNCTION()
	void MoveRight(float val);

	UFUNCTION()
	void Open();

	UFUNCTION()
	void OnJump();
};
