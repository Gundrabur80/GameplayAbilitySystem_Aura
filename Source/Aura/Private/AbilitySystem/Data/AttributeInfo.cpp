// Copyright Martin Jakob


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttribtueTag,
	bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttribtueTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTAg [%s] on AttributeInfo [%s]."), *AttribtueTag.ToString(), *GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}