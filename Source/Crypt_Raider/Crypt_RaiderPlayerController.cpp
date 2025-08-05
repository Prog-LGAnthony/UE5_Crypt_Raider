// Copyright Epic Games, Inc. All Rights Reserved.


#include "Crypt_RaiderPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Crypt_RaiderCameraManager.h"

ACrypt_RaiderPlayerController::ACrypt_RaiderPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ACrypt_RaiderCameraManager::StaticClass();
}

void ACrypt_RaiderPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
