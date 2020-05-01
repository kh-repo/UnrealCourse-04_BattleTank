// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    ATank* AIControlledTank = GetControlledTank();
    if (!AIControlledTank)
    {
        UE_LOG(LogTemp, Error, TEXT("No AI controller found!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AI controller found on %s"), *AIControlledTank->GetName());
    }
}

ATank* ATankAIController::GetControlledTank()
{
    return Cast<ATank>(GetPawn());
}