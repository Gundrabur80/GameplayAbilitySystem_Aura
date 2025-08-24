// Copyright Martin Jakob


#include "AbilitySystem/Abilities/AuraManaSiphon.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

FString UAuraManaSiphon::GetDescription(int32 Level)
{
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	const int32 ManaSiphonPercentage = ManaSiphonCurve.GetValueAtLevel(Level);

	return FString::Printf(TEXT(
		// Title
		"<Title>Mana Siphon</>\n\n"

		// Details
		"<Small>Skill Level:</><Level>%d</>\n"
		"<Small>Mana Cost:</><ManaCost>%.1f</>\n"
		"<Small>Cooldown:</><Cooldown>%.1f</>\n\n"

		// Description
		"<Default>Generates</><Damage> 1 </><Default>Mana Siphon around the character, "
		"recovering</><ManaCost> %d%% </><Default>percent mana of the damage caused.</>\n\n"),

						   Level, ManaCost, Cooldown, ManaSiphonPercentage);
}

FString UAuraManaSiphon::GetNextLevelDescription(int32 Level)
{
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	const int32 ManaSiphonPercentage = ManaSiphonCurve.GetValueAtLevel(Level);

	return FString::Printf(TEXT(
		// Title
		"<Title>Next Level</>\n\n"

		// Details
		"<Small>Skill Level:</><Level>%d</>\n"
		"<Small>Mana Cost:</><ManaCost>%.1f</>\n"
		"<Small>Cooldown:</><Cooldown>%.1f</>\n\n"

		// Description
		"<Default>Generates</><Damage> 1 </><Default>Mana Siphon around the character, "
		"recovering</><ManaCost> %d%% </><Default>percent mana of the damage caused.</>\n\n"),

						   Level, ManaCost, Cooldown, ManaSiphonPercentage);
}

void UAuraManaSiphon::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo())))
	{
		AuraASC->AddLooseGameplayTag(FAuraGameplayTags::Get().Abilities_Passive_ManaSiphon);
	}
}

void UAuraManaSiphon::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(
	  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo())))
	{
		AuraASC->RemoveLooseGameplayTag(FAuraGameplayTags::Get().Abilities_Passive_ManaSiphon);
	}
}
