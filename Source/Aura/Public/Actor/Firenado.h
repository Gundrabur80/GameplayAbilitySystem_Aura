// Copyright Martin Jakob

#pragma once

#include "CoreMinimal.h"
#include "Actor/AuraEffectActor.h"
#include "Firenado.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AFirenado : public AAuraEffectActor
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DefaultLifeSpan = 3.f;
	
	UPROPERTY(BlueprintReadWrite)
	float LifeSpan = 3.f;
	
};
