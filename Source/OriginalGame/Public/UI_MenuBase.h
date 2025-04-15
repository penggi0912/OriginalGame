// Fill out your copyright notice in the Description page of Project Settings.

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
	// メニュー操作時にコントローラーから呼び出す
	UFUNCTION(BlueprintCallable, Category = "Menu Navigation")
	void FocusUp();

	UFUNCTION(BlueprintCallable, Category = "Menu Navigation")
	void FocusDown();

	UFUNCTION(BlueprintCallable, Category = "Menu Navigation")
	void FocusRight();

	UFUNCTION(BlueprintCallable, Category = "Menu Navigation")
	void FocusLeft();

protected:
	// 初期化(ウィジェット作成後に呼ばれる)
	virtual void NativeConstruct() override;
};
