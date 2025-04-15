// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIMenuWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class ORIGINALGAME_API UUIMenuWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
	protected:
		virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

};
