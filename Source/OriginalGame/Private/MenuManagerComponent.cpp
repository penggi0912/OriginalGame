// MenuManagerComponent.cpp

#include "MenuManagerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "UI_MenuBase.h"
#include "GameFramework/PlayerController.h"
#include "Components/Button.h"

UMenuManagerComponent::UMenuManagerComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

// ==============================
// メニュー表示
// ==============================

void UMenuManagerComponent::OpenMenu_Implementation(UUI_MenuBase* MenuWidget)
{
    UE_LOG(LogTemp, Warning, TEXT("OpenMenu called. MenuWidget = %s"), *GetNameSafe(MenuWidget));
    if (!MenuWidget || !IMC_Menu) return;

    // PlayerController取得
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) return;

    // EnhancedInputSubsystem取得
    if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
        {
            // すべてのマッピングを一旦リセットして、IMC_Menuに切り替える
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(IMC_Menu, 1);
        }
    }

    // 入力モードをGame+UIに
    FInputModeGameAndUI Mode;
    Mode.SetWidgetToFocus(MenuWidget->TakeWidget());
    Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    PC->SetInputMode(Mode);
    PC->SetShowMouseCursor(false);

    // 表示とフォーカス
    MenuRef = MenuWidget;
    MenuRef->AddToViewport();
    MenuRef->SetVisibility(ESlateVisibility::Visible);
  
    // メニュー開閉フラグ
    bMenuIsClose = false;
}

// ==============================
// メニュー非表示
// ==============================

void UMenuManagerComponent::CloseMenu()
{
    if (!MenuRef) return;

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) return;

    if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
        {
            // IMC_Menuを外して、IMC_Defaultに戻す
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(IMC_Default, 0);
        }
    }

    // メニュー非表示処理
    MenuRef->RemoveFromParent();
    MenuRef = nullptr;

    // メニュー開閉フラグ
    bMenuIsClose = true;

    // 入力モードをゲーム操作専用に戻す
    PC->SetInputMode(FInputModeGameOnly());
    PC->SetShowMouseCursor(false);
}

// ==============================
// メニューが開いているか確認
// ==============================

// メニュー開閉フラグの状態を返す
bool UMenuManagerComponent::IsMenuClose() const
{
    return bMenuIsClose;
}