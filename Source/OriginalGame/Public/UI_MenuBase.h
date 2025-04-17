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
	// Widget�̏����������B�K�v�ɉ����ē����Ńt�H�[�J�X�ݒ�Ȃǉ\�B
	virtual void NativeConstruct() override;

	// -------------------------
	// Blueprint���ŏ������`����C�x���g�֐��Q�i�t�H�[�J�X�ړ��j
	// -------------------------

	// ������̃t�H�[�J�X�ړ�����������BBlueprint�ŃI�[�o�[���C�h�\�B
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusUp();
	virtual void OnFocusUp_Implementation(); // C++�ł̃f�t�H���g�����i��ł�OK�j

	// �������̃t�H�[�J�X�ړ�
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusDown();
	virtual void OnFocusDown_Implementation();

	// �E�����̃t�H�[�J�X�ړ�
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusRight();
	virtual void OnFocusRight_Implementation();

	// �������̃t�H�[�J�X�ړ�
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MenuNavigation")
	void OnFocusLeft();
	virtual void OnFocusLeft_Implementation();

	// -------------------------
	// C++���ŌĂԂ��߂̃��b�p�[�֐�
	// -------------------------

	// �v���C���[�R���g���[���[�Ȃǂ���Ăяo�������֐��i�����ŏ�̃C�x���g�𔭉΁j
	void FocusUp();
	void FocusDown();
	void FocusLeft();
	void FocusRight();
};
