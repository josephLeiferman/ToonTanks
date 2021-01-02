// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));

    TEST();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition() 
{
    // Check if Player == null || is dead then do not fire
    if(!PlayerPawn) 
    {
        return;
    }

    // If player IS in range then fire!
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        UE_LOG(LogTemp, Warning, TEXT("Fire condition success"));
    }
}

float APawnTurret::ReturnDistanceToPlayer() 
{
     if(!PlayerPawn) 
    {
        return 0.0f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

}
