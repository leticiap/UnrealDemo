// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FPScppDemoGameMode.h"
#include "FPScppDemoHUD.h"
#include "FPScppDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPScppDemoGameMode::AFPScppDemoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPScppDemoHUD::StaticClass();
}
