// Copyright Martin Jakob


#include "UI/HUD/AuraLoadMenuHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/ViewModel/MVVM_LoadScreen.h"
#include "UI/Widget/LoadScreenWidget.h"

void AAuraLoadMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	
	LoadScreenViewModel = NewObject<UMVVM_LoadScreen>(this, LoadScreenViewModelClass);
	
	LoadScreedWidget = CreateWidget<ULoadScreenWidget>(GetWorld(), LoadScreedWidgetClass);
	LoadScreedWidget->AddToViewport();
}
