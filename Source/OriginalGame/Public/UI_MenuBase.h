// UI_MenuBase.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_MenuBase.generated.h"

/**
 * 
 */
UCLASS()
class ORIGINALGAME_API UUI_MenuBase : public UUserWidget
{
	GENERATED_BODY()

public:
	// Widgetの初期化処理。必要に応じて内部でフォーカス設定など可能。
	virtual void NativeConstruct() override;

	// -------------------------
	// Blueprint側で処理を定義するイベント関数群（フォーカス移動）
	// -------------------------

	// 上方向のフォーカス移動を処理する。Blueprintでオーバーライド可能。
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusUp();
	virtual void OnFocusUp_Implementation(); // C++でのデフォルト実装（空でもOK）

	// 下方向のフォーカス移動
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusDown();
	virtual void OnFocusDown_Implementation();

	// 右方向のフォーカス移動
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusRight();
	virtual void OnFocusRight_Implementation();

	// 左方向のフォーカス移動
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusLeft();
	virtual void OnFocusLeft_Implementation();

	// -------------------------
	// C++側で呼ぶためのラッパー関数
	// -------------------------

	// プレイヤーコントローラーなどから呼び出される実関数（内部で上のイベントを発火）
	void FocusUp();
	void FocusDown();
	void FocusLeft();
	void FocusRight();
};
