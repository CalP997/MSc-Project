// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "LevelSequence/Public/LevelSequenceActor.h"
#include "LevelSequence/Public/LevelSequencePlayer.h"
#include "MyCharacter.generated.h"


UCLASS()
class PROGRAMYOURESCAPE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//array to store order for order puzzle in level2
	UPROPERTY()
		TArray<int> orderCodeLvl2;

	//array to store order for match up puzzle in level2
	UPROPERTY()
		TArray<int> matchCodeLvl2;

	//array to store order for order puzzle in level3
	UPROPERTY()
		TArray<int> orderCodeLvl3;

	//array to store order for match up puzzle in level3
	UPROPERTY()
		TArray<int> matchCodeLvl3;

	//references to animations
	UPROPERTY(EditAnywhere)
		ALevelSequenceActor* safeHinge;

protected:
	//create player movement
	void VerticalMove(float AxisVal);
	void HorizontalMove(float AxisVal);

private:
	//create button interaction function
	void ButtonInteract();
};
