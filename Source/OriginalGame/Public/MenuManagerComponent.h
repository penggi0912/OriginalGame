// MenuManagerComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MenuManagerComponent.generated.h"

class UInputMappingContext;
class UUI_MenuBase;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ORIGINALGAME_API UMenuManagerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UMenuManagerComponent();

    // ========================
    // メニュー表示制御
    // ========================

    /*
    * メニューを開く（C++とBlueprintから拡張可能）
    */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Menu")
    void OpenMenu(UUI_MenuBase* MenuWidget);
    virtual void OpenMenu_Implementation(UUI_MenuBase* MenuWidget);

    /*
    * メニューを閉じる（呼び出しはBlueprint or C++）
    */
    UFUNCTION(BlueprintCallable, Category = "Menu")
    void CloseMenu();

    
    // ()の中は空でもいいけど、このほうがC++からはprivateにしつつ、ブループリントからも読めてデバッグでも見やすい
    UPROPERTY(BlueprintReadOnly, Category = "Menu", meta = (AllowPrivateAccess = "true"))  
    // メニュー開閉フラグ
    bool bMenuIsClose = true;

    /*
    * メニュー開閉フラグを返す関数
    */
    UFUNCTION(BlueprintCallable, Category = "Menu")
    bool IsMenuClose() const;

    // ========================
    // Enhanced Input Context
    // ========================

    // メニュー時のMappingContext
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* IMC_Menu;

    // 通常時（ゲーム操作）のMappingContext
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* IMC_Default;

private:
    // 現在表示中のメニュー（nullptrなら未表示）
    UPROPERTY()
    UUI_MenuBase* MenuRef;
};
