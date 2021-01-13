// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"


void ATankGameModeBase::BeginPlay() 
{
    // Get references and game win/lose conditions

    // Call HandleGameStart() to intialize the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of Actor died if turre, tally, If Player -> go to lose condition
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // See if the player has destroyed all of the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call blueprint version GameOver(bool).
}

void ATankGameModeBase::HandleGameStart() 
{
    // Initialize the start countdown, turrect activation, pawn check etc.
    // Call Blueprint version GameStart();
}
