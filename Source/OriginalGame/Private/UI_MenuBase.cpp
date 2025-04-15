// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MenuBase.h"
#include "Kismet/KismetSystemLibrary.h"

void UUI_MenuBase::NativeConstruct()
{
	Super::NativeConstruct();

	// �K�v�ł���΂����ŏ����t�H�[�J�X�ݒ�Ȃǂ��\
	// ��: SetKeyboardFocus() �Ȃ�
}

void UUI_MenuBase::FocusUp()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusUp called"));

	// ���ۂ̃��W�b�N�̓E�B�W�F�b�g���őg��
	// ��: ���ݑI�𒆂̃{�^���̏�̃E�B�W�F�b�g�Ƀt�H�[�J�X���ڂ��A�Ȃ�
}

void UUI_MenuBase::FocusDown()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusDown called"));
}

void UUI_MenuBase::FocusLeft()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusLeft called"));
}

void UUI_MenuBase::FocusRight()
{
	UE_LOG(LogTemp, Log, TEXT("UI: FocusRight called"));
}
