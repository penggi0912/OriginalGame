// Fill out your copyright notice in the Description page of Project Settings.


#include "UIMenuWidgetBase.h"
#include "InputCoreTypes.h"
#include "Kismet/KismetSystemLibrary.h"

FReply UUIMenuWidgetBase::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	const FKey PressedKey = InKeyEvent.GetKey();

	if (PressedKey == EKeys::W || PressedKey == EKeys::Gamepad_DPad_Up ||
		PressedKey == EKeys::S || PressedKey == EKeys::Gamepad_DPad_Down ||
		PressedKey == EKeys::A || PressedKey == EKeys::Gamepad_DPad_Left ||
		PressedKey == EKeys::D || PressedKey == EKeys::Gamepad_DPad_Right) {
		return FReply::Handled();
	}

	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
};