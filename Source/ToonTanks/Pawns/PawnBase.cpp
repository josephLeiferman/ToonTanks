// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

void APawnBase::RotateTurret(FVector LookAtTarget) 
{
	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();

	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire() 
{
	// Get ProjectileSpawnPoint Location && Rotation -> Spawn Projectile class at Location firing towards rotation.
	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Success"));

}

void APawnBase::HandleDesctruction() 
{
	// ---- Universal functionality ---
	// Play death effects particles, sound and camera shake.

	// --- then do child overrides ---
	// -- PawnTurret - Inform GameMode Turret died -> Then Destroy() self.

	// -- PawnTank -  Inform GameMode Player died -> Then Hide() all components && stop movement input.
}
