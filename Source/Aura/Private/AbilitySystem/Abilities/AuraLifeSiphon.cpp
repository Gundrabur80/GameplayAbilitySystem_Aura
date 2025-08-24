// Copyright Martin Jakob


#include "AbilitySystem/Abilities/AuraLifeSiphon.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

FString UAuraLifeSiphon::GetDescription(int32 Level)
{
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	const int32 LifeSiphonPercentage = LifeSiphonCurve.GetValueAtLevel(Level);

	return FString::Printf(TEXT(
		// Title
		"<Title>Life Siphon</>\n\n"

		// Details
		"<Small>Skill Level:</><Level>%d</>\n"
		"<Small>Mana Cost:</><ManaCost>%.1f</>\n"
		"<Small>Cooldown:</><Cooldown>%.1f</>\n\n"

		// Description
		"<Default>Generates</><Damage> 1 </><Default>life Siphon around the character, "
		"healing</><ManaCost> %d%% </><Default>percent of the damage caused.</>\n\n"),

						   Level, ManaCost, Cooldown, LifeSiphonPercentage);
}

FString UAuraLifeSiphon::GetNextLevelDescription(int32 Level)
{
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	const int32 LifeSiphonPercentage = LifeSiphonCurve.GetValueAtLevel(Level);

	return FString::Printf(TEXT(
		// Title
		"<Title>Next Level</>\n\n"

		// Details
		"<Small>Skill Level:</><Level>%d</>\n"
		"<Small>Mana Cost:</><ManaCost>%.1f</>\n"
		"<Small>Cooldown:</><Cooldown>%.1f</>\n\n"

		// Description
		"<Default>Generates</><Damage> 1 </><Default>life Siphon around the character, "
		"healing</><ManaCost> %d%% </><Default>percent of the damage caused.</>\n\n"),

						   Level, ManaCost, Cooldown, LifeSiphonPercentage);
}

void UAuraLifeSiphon::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo())))
	{
		AuraASC->AddLooseGameplayTag(FAuraGameplayTags::Get().Abilities_Passive_LifeSiphon);
	}
}

void UAuraLifeSiphon::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(
	  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo())))
	{
		AuraASC->RemoveLooseGameplayTag(FAuraGameplayTags::Get().Abilities_Passive_LifeSiphon);
	}
}
