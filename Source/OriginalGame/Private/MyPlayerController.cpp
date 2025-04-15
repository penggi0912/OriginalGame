// MyPlayerController.cpp

#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI_MenuBase.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MenuMappingContext, 1); // IMC_Menu
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &AMyPlayerController::OnMoveUp);
		EnhancedInput->BindAction(MoveDownAction, ETriggerEvent::Triggered, this, &AMyPlayerController::OnMoveDown);
		EnhancedInput->BindAction(MoveLeftAction, ETriggerEvent::Triggered, this, &AMyPlayerController::OnMoveLeft);
		EnhancedInput->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AMyPlayerController::OnMoveRight);
	}
}

void AMyPlayerController::OnMoveUp(const FInputActionInstance& Instance)
{
	if (MenuWidgetRef)
	{
		MenuWidgetRef->FocusUp();
	}
}

void AMyPlayerController::OnMoveDown(const FInputActionInstance& Instance)
{
	if (MenuWidgetRef)
	{
		MenuWidgetRef->FocusDown();
	}
}

void AMyPlayerController::OnMoveLeft(const FInputActionInstance& Instance)
{
	if (MenuWidgetRef)
	{
		MenuWidgetRef->FocusLeft();
	}
}

void AMyPlayerController::OnMoveRight(const FInputActionInstance& Instance)
{
	if (MenuWidgetRef)
	{
		MenuWidgetRef->FocusRight();
	}
}
