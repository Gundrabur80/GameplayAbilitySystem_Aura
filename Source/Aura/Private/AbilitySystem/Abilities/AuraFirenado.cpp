// Copyright Martin Jakob


#include "AbilitySystem/Abilities/AuraFirenado.h"

#include "Actor/Firenado.h"

FString UAuraFirenado::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>FIRENADO</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"
			// ManacCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Summon a tornado of fire, "
			"which remains for 3 seconds"
			", causing radial fire damage of </>"

			// Damage
			"<Damage>%d</><Default> at the tornado's origin</>"),


			// Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>FIRENADO</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"
			// ManacCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Summon a tornado of fire, "
			"which remains for 3 seconds"
			", causing radial fire damage of </>"

			// Damage
			"<Damage>%d</><Default> at the tornado's origin</>"),


			// Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
}

FString UAuraFirenado::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
			// Title
			"<Title>NEXT LEVEL</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"
			// ManacCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Summon a tornado of fire, "
			"which remains for 3 seconds"
			", causing radial fire damage of </>"

			// Damage
			"<Damage>%d</><Default> at the tornado's origin</>"),


			// Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
}
