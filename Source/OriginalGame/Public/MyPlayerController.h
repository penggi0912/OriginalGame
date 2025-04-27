// MyPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UUI_MenuBase;

UCLASS()
class ORIGINALGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

    /*
    * ゲーム開始時にIMC_Menuを割り当て
    * 現状は使用しないのでコメントアウト
    * 将来的にゲーム開始時のIMCをIMC_Menuに統合するから残しておく
    protected:
	    virtual void BeginPlay() override;
     */

    public:
	    virtual void SetupInputComponent() override;

        // メニュー内のフォーカス移動関数
        UFUNCTION()
        void OnMenuMove(const struct FInputActionValue& Value);

        // メニュー用Lスティック&WASDのInput Actionを宣言(バインド用)
        UPROPERTY(EditDefaultsOnly, Category = "Input")
        UInputAction* IA_MenuMove;
    
	    // IMC, IA をエディタで設定できるように宣言
	    UPROPERTY(EditDefaultsOnly, Category = "Input")
	    UInputMappingContext* IMC_Menu;

        // スティック入力のしきい値
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
        float StickInputThreshold = 0.4f;

    // 表示中のメニュー参照を渡せるようにする
    private:
	    UPROPERTY()
	    UUI_MenuBase* CurrentMenu;

    public:
	    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Menu")
	    void SetCurrentMenu(UUI_MenuBase* Menu);
	    virtual void SetCurrentMenu_Implementation(UUI_MenuBase* Menu);
};