// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ATank* TankPlayerController = GetControlledTank();
    if (!TankPlayerController)
    {
        UE_LOG(LogTemp, Error, TEXT("No player controller found!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Found player controller on %s"), *TankPlayerController->GetName());
    }
    
    
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
