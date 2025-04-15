// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MenuBase.h"
#include "Kismet/KismetSystemLibrary.h"

void UUI_MenuBase::NativeConstruct()
{
	Super::NativeConstruct();

	// 必要であればここで初期フォーカス設定なども可能
	// 例: SetKeyboardFocus() など
}

void UUI_MenuBase::FocusUp()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusUp called"));

	// 実際のロジックはウィジェット側で組む
	// 例: 現在選択中のボタンの上のウィジェットにフォーカスを移す、など
}

void UUI_MenuBase::FocusDown()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusDown called"));
}

void UUI_MenuBase::FocusLeft()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusLeft called"));
}

void UUI_MenuBase::FocusRight()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusRight called"));
}
