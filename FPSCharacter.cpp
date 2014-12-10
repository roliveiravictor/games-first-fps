

#include "AlanThornsBook01.h"
#include "FPSCharacter.h"


AFPSCharacter::AFPSCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Create a CameraComponent
	FirstPersonCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = CapsuleComponent;

	//Positioning the camera a bit above the eyse
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 50.0f + BaseEyeHeight);
	//Allow the pawn to control rotation
	FirstPersonCameraComponent->bUseControllerViewRotation = true;


	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	FirstPersonMesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("FirstPersonMesh"));
	
	// Only player will see this mesh
	FirstPersonMesh->SetOnlyOwnerSee(true); 
	FirstPersonMesh->AttachParent = FirstPersonCameraComponent;
	FirstPersonMesh->bCastDynamicShadow = false;
	FirstPersonMesh->CastShadow = false;

	// everyone but the owner can see the regular body mesh
	Mesh->SetOwnerNoSee(true);
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	// Setup GamePlay Keybinds
	InputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	
	InputComponent->BindAction("Open", IE_Released, this, &AFPSCharacter::Open);	
	InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::OnJump);
}

void AFPSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		
		// Find which way is forward
		FRotator Rotation = Controller->GetControlRotation();

		
		// Limit pitch when walking or falling
		if (CharacterMovement->IsMovingOnGround() || CharacterMovement->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}

		// Add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		
		// Find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		
		//Add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::Open()
{
	// Do the math
}

void AFPSCharacter::OnJump()
{
	// Do the math
}