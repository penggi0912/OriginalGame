// UI_MenuBase.cpp

#include "UI_MenuBase.h"
#include "Kismet/KismetSystemLibrary.h"

// �e�����̊֐��́ABlueprint�����C�x���g���Ăяo���iBlueprint�ŏ����ł���悤�ɂ���j

void UUI_MenuBase::NativeConstruct()
{
	Super::NativeConstruct();

	// �K�v�ł���΂����ŏ����t�H�[�J�X�ݒ�Ȃǂ��\
	// �E�B�W�F�b�g���̂Ƀt�H�[�J�X
	SetFocus();
}

// �K�v�ɉ����Ċe�֐��̒��Ƀf�t�H���g�����������i��ł�OK�j
void UUI_MenuBase::OnFocusUp_Implementation() {}  
void UUI_MenuBase::OnFocusDown_Implementation() {}
void UUI_MenuBase::OnFocusRight_Implementation() {}
void UUI_MenuBase::OnFocusLeft_Implementation() {}


// C++����Ăяo�����b�p�[�֐��Q�iBlueprint�C�x���g�𔭉΁j
void UUI_MenuBase::FocusUp()
{
	OnFocusUp();
}

void UUI_MenuBase::FocusDown()
{
	OnFocusDown();
}

void UUI_MenuBase::FocusRight()
{
	OnFocusRight();
}

void UUI_MenuBase::FocusLeft()
{
	OnFocusLeft();
}