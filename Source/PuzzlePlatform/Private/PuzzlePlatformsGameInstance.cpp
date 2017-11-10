// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"

#include "Engine/Engine.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{

	UE_LOG(LogTemp, Warning, TEXT("Game instance constructor"));

}


void UPuzzlePlatformsGameInstance::Init()
{

	UE_LOG(LogTemp, Warning, TEXT("Game init"));	
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine * Engine = GetEngine();
	if (!Engine) { return; }

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));
	UE_LOG(LogTemp, Warning, TEXT("Hello Host!"))

	UWorld * World = GetWorld();
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
	UE_LOG(LogTemp, Warning, TEXT("Hello World"))
	
}

void UPuzzlePlatformsGameInstance::Join(const FString &Address)
{
	UEngine * Engine = GetEngine();
	if (!Engine) { return; }

	FString IPMessage = FString::Printf(TEXT("Joiner is %s"), *Address);

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, IPMessage);
	UE_LOG(LogTemp, Warning, TEXT("Hello Host!"))

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController)) { return; }

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);

}


/*
void UPuzzlePlatformGameInstance::BeginPlay()
{

	Super::BeginPlay();

}*/
