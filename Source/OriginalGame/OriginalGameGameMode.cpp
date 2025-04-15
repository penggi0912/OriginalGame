// Copyright Epic Games, Inc. All Rights Reserved.

#include "OriginalGameGameMode.h"
#include "OriginalGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOriginalGameGameMode::AOriginalGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
