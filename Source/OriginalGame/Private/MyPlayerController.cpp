// MyPlayerController.cpp

#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI_MenuBase.h"
#include "Blueprint/WidgetLayoutLibrary.h"

/*
* ゲーム開始時にIMC_Menuを割り当て
* 現状は使用しないのでコメントアウト
* 将来的にゲーム開始時のIMCをIMC_Menuに統合するから残しておく
void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_Menu, 0); // IMC_Menu
	}
}
*/

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
        UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent acquired"));
        EnhancedInput->BindAction(IA_MenuMove, ETriggerEvent::Triggered, this, &AMyPlayerController::OnMenuMove);
	}
    else
    {
        UE_LOG(LogTemp, Error, TEXT("EnhancedInputComponent NOT found"));
    }
}

void AMyPlayerController::SetCurrentMenu_Implementation(UUI_MenuBase* Menu) 
{
	CurrentMenu = Menu;

	FInputModeGameAndUI Mode;
	Mode.SetWidgetToFocus(Menu->TakeWidget());
	SetInputMode(Mode);
	SetShowMouseCursor(false);

}

// メニュー画面で左スティック(IA_MenuMove)を使ったフォーカス移動方向の判定処理
void AMyPlayerController::OnMenuMove(const FInputActionValue& Value)
{
    if (!CurrentMenu) return;

    FVector2D Dir = Value.Get<FVector2D>();

    // 入力値がほぼゼロの場合は何もしない
    if (Dir.Size() < 0.1f) return;

    // 補正して上下を反転
    float CorrectedY = -Dir.Y;
    
    // 絶対値で大小を比較（方向性はあとで使う）
    float AbsX = FMath::Abs(Dir.X);
    float AbsY = FMath::Abs(CorrectedY);



    // Y（上下）の方が強ければ上下処理
    if (AbsY > AbsX)
    {
        if (CorrectedY > StickInputThreshold)  // StickInputThresholdは入力しきい値
        {
            CurrentMenu->FocusDown();  // 手前に倒す(下移動)
        }
        else if (CorrectedY < -StickInputThreshold)
        {
            CurrentMenu->FocusUp();  // 奥に倒す(上移動)
        }
    }
    // X（左右）の方が強ければ左右処理
    else
    {
        if (Dir.X > StickInputThreshold)
        {
            CurrentMenu->FocusRight();
        }
        else if (Dir.X < -StickInputThreshold)
        {
            CurrentMenu->FocusLeft();
        }
    }

    // 入力値のログ出力
    UE_LOG(LogTemp, Warning, TEXT("Dir: X=%.3f Y=%.3f | CorrectedY=%.3f | AbsX=%.3f AbsY=%.3f"),
                Dir.X, Dir.Y, CorrectedY, AbsX, AbsY);
}
