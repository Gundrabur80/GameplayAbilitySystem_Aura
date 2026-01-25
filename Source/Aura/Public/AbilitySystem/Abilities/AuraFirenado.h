// Copyright Martin Jakob

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraDamageGameplayAbility.h"
#include "AuraFirenado.generated.h"

class AFirenado;
/**
 * 
 */
UCLASS()
class AURA_API UAuraFirenado : public UAuraDamageGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	virtual FString GetDescription(int32 Level) override;
	virtual FString GetNextLevelDescription(int32 Level) override;
	
private:
	
	UPROPERTY(EditDefaultsOnly)
	AFirenado* FirenadoClass;
	
};
