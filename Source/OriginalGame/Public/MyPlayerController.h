// MyPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "MyPlayerController.generated.h"

class UUI_MenuBase;

UCLASS()
class ORIGINALGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	// ���̓o�C���f�B���O
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* MenuMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveUpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveDownAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveLeftAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveRightAction;

public:
	// ���j���[�Q�Ƃ�n����悤�ɂ���
	UPROPERTY()
	UUI_MenuBase* MenuWidgetRef;

	// ���͎󂯎���
	void OnMoveUp(const FInputActionInstance& Instance);
	void OnMoveDown(const FInputActionInstance& Instance);
	void OnMoveLeft(const FInputActionInstance& Instance);
	void OnMoveRight(const FInputActionInstance& Instance);
};

