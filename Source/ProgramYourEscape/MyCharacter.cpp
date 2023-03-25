// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//bind axis for movement
	PlayerInputComponent->BindAxis("HorizontalMove", this, &AMyCharacter::HorizontalMove);
	PlayerInputComponent->BindAxis("VerticalMove", this, &AMyCharacter::VerticalMove);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction("InteractButton", IE_Pressed, this, &AMyCharacter::ButtonInteract);
}

//movement functions for the player character

//Horizontal (left/right) movement
void AMyCharacter::HorizontalMove(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}

//Vertical (back/forward) movement
void AMyCharacter::VerticalMove(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

//button interaction
void AMyCharacter::ButtonInteract()
{
	//detect when object hit
	FHitResult* hit = new FHitResult();
	FVector forward = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetActorForwardVector();
	FVector start = GetActorLocation();
	start.Z = 130.0f;
	FVector end = (forward * 1000.0f) + start;
	FCollisionQueryParams col;
	//ignore player collision
	col.AddIgnoredActor(this);
	if (GetWorld()->LineTraceSingleByChannel(*hit, start, end, ECC_WorldStatic, col))
	{
		DrawDebugLine(GetWorld(), start, end, FColor::Blue, true);
		if (hit->GetActor() != NULL)
		{
			UE_LOG(LogClass, Log, TEXT("Component: %s"), *hit->GetComponent()->GetName());

			//code for lvl2 order puzzle
			
			//check if hitting button1
			if (*hit->GetComponent()->GetName() == FString("1"))
			{
				orderCodeLvl2.Add(1);
			}
			//check if hitting button2
			else if (*hit->GetComponent()->GetName() == FString("2"))
			{
				orderCodeLvl2.Add(2);
			}
			//check if hitting button3
			else if (*hit->GetComponent()->GetName() == FString("3"))
			{
				orderCodeLvl2.Add(3);
			}
			//check array length
			if (orderCodeLvl2.Num() == 3)
			{
				//order checker boolean
				bool correctOrder = false;
				int count = 0;
				for (int i = 0; i < orderCodeLvl2.Num(); i++)
				{
					if (orderCodeLvl2[i] == i + 1)
					{

						correctOrder = true;
						UE_LOG(LogClass, Log, TEXT("Correct"));
						count++;
					}
					else 
					{
						correctOrder = false;
						UE_LOG(LogClass, Log, TEXT("Incorrect"));
						break;
					}
				}
				//clear array
				orderCodeLvl2.Empty();

				/*if (count = 2)
				{
					UE_LOG(LogClass, Log, TEXT("Open Safe"));
					safeHinge->SequencePlayer->Play();
					
				}*/
				
			}
		}
	}
}

