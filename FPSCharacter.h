/**********************************************************************/
/*                                                                    */
/*         Game: First FPS											  */
/*		   Author: Victor Rocha                                       */
/*																	  */
/*		   This a FPS game made to study UE4 concepts. It's			  */
/*		   the first FPS game I ever made.							  */
/*                                                                    */
/**********************************************************************/

#pragma once

#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPS_API AFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AFPSCharacter(const FObjectInitializer& ObjectInitializer);

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
        UCameraComponent* FirstPersonCameraComponent;

    // 1st person mesh Arms seen only by self
    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
        USkeletalMeshComponent* FirstPersonMesh;

    UFUNCTION()
        void MoveForward(float val);

    UFUNCTION()
        void MoveRight(float val);

    UFUNCTION()
        void Open();

    UFUNCTION()
        void OnJump();
};
