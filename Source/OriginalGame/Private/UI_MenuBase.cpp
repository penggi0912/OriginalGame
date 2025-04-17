// UI_MenuBase.cpp

#include "UI_MenuBase.h"
#include "Kismet/KismetSystemLibrary.h"

// 各方向の関数は、Blueprint実装イベントを呼び出す（Blueprintで処理できるようにする）

void UUI_MenuBase::NativeConstruct()
{
	Super::NativeConstruct();

	// 必要であればここで初期フォーカス設定なども可能
	// ウィジェット自体にフォーカス
	SetFocus();
}

// 必要に応じて各関数の中にデフォルト処理を書く（空でもOK）
void UUI_MenuBase::OnFocusUp_Implementation() {}  
void UUI_MenuBase::OnFocusDown_Implementation() {}
void UUI_MenuBase::OnFocusRight_Implementation() {}
void UUI_MenuBase::OnFocusLeft_Implementation() {}


// C++から呼び出すラッパー関数群（Blueprintイベントを発火）
void UUI_MenuBase::FocusUp()
{
	OnFocusUp();
}

void UUI_MenuBase::FocusDown()
{
	OnFocusDown();
}

void UUI_MenuBase::FocusRight()
{
	OnFocusRight();
}

void UUI_MenuBase::FocusLeft()
{
	OnFocusLeft();
}