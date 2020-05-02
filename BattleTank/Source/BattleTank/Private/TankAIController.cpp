// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    ATank* PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIcontroller found player: %s"), *PlayerTank->GetName());
    }
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (GetPlayerTank())
    {
        // TODO Move towards the player
        
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

        // Fire if ready
    }
    
}

ATank* ATankAIController::GetControlledTank()
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    return Cast<ATank>(PlayerPawn);
}