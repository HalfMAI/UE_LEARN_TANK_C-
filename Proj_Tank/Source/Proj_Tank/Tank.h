// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDeathDelegate);

UCLASS()
class PROJ_TANK_API ATank : public APawn
{
	GENERATED_BODY()


private:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Setup")
	float GetHealthPercent() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float StartHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	float CurrentHealth = 0;

public:
	FTankDeathDelegate OnTankDeath;
};
