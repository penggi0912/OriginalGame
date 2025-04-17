// MyPlayerController.cpp

#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI_MenuBase.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_Menu, 1); // IMC_Menu
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(IA_FocusUp, ETriggerEvent::Triggered, this, &AMyPlayerController::OnFocusUp);
		EnhancedInput->BindAction(IA_FocusDown, ETriggerEvent::Triggered, this, &AMyPlayerController::OnFocusDown);
		EnhancedInput->BindAction(IA_FocusRight, ETriggerEvent::Triggered, this, &AMyPlayerController::OnFocusRight);
		EnhancedInput->BindAction(IA_FocusLeft, ETriggerEvent::Triggered, this, &AMyPlayerController::OnFocusLeft);
	}
}

void AMyPlayerController::SetCurrentMenu_Implementation(UUI_MenuBase* Menu) 
{
	CurrentMenu = Menu;

	FInputModeGameAndUI Mode;
	Mode.SetWidgetToFocus(Menu->TakeWidget());
	SetInputMode(Mode);
	SetShowMouseCursor(false);

	Menu->SetFocus();
}

void AMyPlayerController::OnFocusUp(const FInputActionValue& Value)
{
	(void)Value;  // 未使用であることを明示
	if (CurrentMenu)
	{
		CurrentMenu->FocusUp();
	}
}

void AMyPlayerController::OnFocusDown(const FInputActionValue& Value)
{
	(void)Value;  // 未使用であることを明示
	if (CurrentMenu)
	{
		CurrentMenu->FocusDown();
	}
}

void AMyPlayerController::OnFocusRight(const FInputActionValue& Value)
{
	(void)Value;  // 未使用であることを明示
	if (CurrentMenu)
	{
		CurrentMenu->FocusRight();
	}
}

void AMyPlayerController::OnFocusLeft(const FInputActionValue& Value)
{
	(void)Value;  // 未使用であることを明示
	if (CurrentMenu)
	{
		CurrentMenu->FocusLeft();
	}
}