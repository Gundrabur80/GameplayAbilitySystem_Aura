// Copyright Martin Jakob

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraLoadMenuHUD.generated.h"

class UMVVM_LoadScreen;
class ULoadScreenWidget;
/**
 * 
 */
UCLASS()
class AURA_API AAuraLoadMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> LoadScreedWidgetClass;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ULoadScreenWidget> LoadScreedWidget;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMVVM_LoadScreen> LoadScreenViewModelClass;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UMVVM_LoadScreen> LoadScreenViewModel;
	
protected:
	
	virtual void BeginPlay();
	
};
