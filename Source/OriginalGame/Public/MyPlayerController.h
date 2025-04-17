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

protected:
	virtual void BeginPlay() override;


public:
	virtual void SetupInputComponent() override;

	// IMC, IA をエディタで設定できるように
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* IMC_Menu;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_FocusUp;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_FocusDown;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_FocusRight;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_FocusLeft;

	// 入力受け取り先
	void OnFocusUp(const FInputActionValue& Value);
	void OnFocusDown(const FInputActionValue& Value);
	void OnFocusRight(const FInputActionValue& Value);
	void OnFocusLeft(const FInputActionValue& Value);

private:
	// 表示中のメニュー参照を渡せるようにする
	UPROPERTY()
	UUI_MenuBase* CurrentMenu;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Menu")
	void SetCurrentMenu(UUI_MenuBase* Menu);
	virtual void SetCurrentMenu_Implementation(UUI_MenuBase* Menu);
};