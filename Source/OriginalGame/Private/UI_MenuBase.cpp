// UI_MenuBase.cpp

#include "UI_MenuBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "InputCoreTypes.h"

// 各方向の関数は、Blueprint実装イベントを呼び出す（Blueprintで処理できるようにする）

void UUI_MenuBase::NativeConstruct()
{
	Super::NativeConstruct();
}

// 必要に応じて各関数の中にデフォルト処理を書く（空でもOK）
void UUI_MenuBase::OnFocusUp_Implementation() {}  
void UUI_MenuBase::OnFocusDown_Implementation() {}
void UUI_MenuBase::OnFocusLeft_Implementation() {}
void UUI_MenuBase::OnFocusRight_Implementation() {}


// C++から呼び出すラッパー関数群（Blueprintイベントを発火）
void UUI_MenuBase::FocusUp()
{
	OnFocusUp();
}

void UUI_MenuBase::FocusDown()
{
	OnFocusDown();
}

void UUI_MenuBase::FocusLeft()
{
    OnFocusLeft();
}

void UUI_MenuBase::FocusRight()
{
	OnFocusRight();
}



// PreviewKeyDownのオーバーライド（十字キー / 矢印キーの入力を拾う）
FReply UUI_MenuBase::NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    const FKey PressedKey = InKeyEvent.GetKey();
    const float CurrentTime = GetWorld()->GetTimeSeconds();

    // 入力インターバル制御（0.15秒以内なら無視）
    if (CurrentTime - LastInputTime < InputInterval)
    {
        return FReply::Unhandled(); // 入力を通さない
    }

    // 入力処理
    if (PressedKey == EKeys::Up || PressedKey == EKeys::Gamepad_DPad_Up)
    {
        FocusUp();
        LastInputTime = CurrentTime;
        return FReply::Handled();
    }
    if (PressedKey == EKeys::Down || PressedKey == EKeys::Gamepad_DPad_Down)
    {
        FocusDown();
        LastInputTime = CurrentTime;
        return FReply::Handled();
    }
    if (PressedKey == EKeys::Left || PressedKey == EKeys::Gamepad_DPad_Left)
    {
        FocusLeft();
        LastInputTime = CurrentTime;
        return FReply::Handled();
    }
    if (PressedKey == EKeys::Right || PressedKey == EKeys::Gamepad_DPad_Right)
    {
        FocusRight();
        LastInputTime = CurrentTime;
        return FReply::Handled();
    }

    return Super::NativeOnPreviewKeyDown(InGeometry, InKeyEvent);
}