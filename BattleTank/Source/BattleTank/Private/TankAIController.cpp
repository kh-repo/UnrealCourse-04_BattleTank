// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

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

ATank* ATankAIController::GetControlledTank()
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    
    return Cast<ATank>(PlayerPawn);
}