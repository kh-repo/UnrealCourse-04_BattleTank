// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ATank* PlayerControlledTank = GetControlledTank();
    if (!PlayerControlledTank)
    {
        UE_LOG(LogTemp, Error, TEXT("No player controller found!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Found player controller on %s"), *PlayerControlledTank->GetName());
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }

    // Get world location if linetrace through crosshair
    // If it hits the landscape
        // Tell the controlled tank to aim at this point
}