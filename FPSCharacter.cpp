/**********************************************************************/
/*                                                                    */
/*         Game: First FPS											  */
/*		   Author: Victor Rocha                                       */
/*																	  */
/*		   This a FPS game made to study UE4 concepts. It's			  */
/*		   the first FPS game I ever made.							  */
/*                                                                    */
/**********************************************************************/

#include "FPS.h"
#include "FPSCharacter.h"

AFPSCharacter::AFPSCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create a CameraComponent
    FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();

    //Positioning the camera a bit above the eyse
    FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 50.0f + BaseEyeHeight);
    //Allow the pawn to control rotation
    FirstPersonCameraComponent->bUsePawnControlRotation = true;


    // Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
    FirstPersonMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("FirstPersonMesh"));

    // Only player will see this mesh
    FirstPersonMesh->SetOnlyOwnerSee(true);
    FirstPersonMesh->AttachParent = FirstPersonCameraComponent;
    FirstPersonMesh->bCastDynamicShadow = false;
    FirstPersonMesh->CastShadow = false;

    // everyone but the owner can see the regular body mesh
    GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPSCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

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
    if ((GetController() != NULL) && (Value != 0.0f))
    {
        // Find which way is forward
        FRotator Rotation = GetController()->GetControlRotation();


        // Limit pitch when walking or falling
        if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
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