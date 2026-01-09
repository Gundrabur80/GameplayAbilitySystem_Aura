// Copyright Martin Jakob

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MVVM_LoadScreen.generated.h"

class UAuraMVVM_LoadSlot;
/**
 * 
 */
UCLASS()
class AURA_API UMVVM_LoadScreen : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
public:
	
	void InitializeLoadSlots();
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAuraMVVM_LoadSlot> LoadSlotViewModelClass;
	
	UFUNCTION(BlueprintPure)
	UAuraMVVM_LoadSlot* GetLoadSlotViewModelByIndex(int32 Index) const;
	
private:
	
	UPROPERTY()
	TMap<int32, UAuraMVVM_LoadSlot*> LoadSlots;
	
	UPROPERTY()
	TObjectPtr<UAuraMVVM_LoadSlot> LoadSlot_0;
	
	UPROPERTY()
	TObjectPtr<UAuraMVVM_LoadSlot> LoadSlot_1;
	
	UPROPERTY()
	TObjectPtr<UAuraMVVM_LoadSlot> LoadSlot_2;
	
};
