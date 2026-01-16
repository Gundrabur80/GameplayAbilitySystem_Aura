// Copyright Martin Jakob


#include "UI/ViewModel/AuraMVVM_LoadSlot.h"

void UAuraMVVM_LoadSlot::InitializeSlot()
{
	const int32 WidgetSwitcherIndex = SlotStatus.GetIntValue();
	SetWidgetSwitcherIndex.Broadcast(WidgetSwitcherIndex);
}

void UAuraMVVM_LoadSlot::SetPlayerName(FString InPlayerName)
{
	UE_MVVM_SET_PROPERTY_VALUE(PlayerName, InPlayerName);
}

void UAuraMVVM_LoadSlot::SetLoadSlotName(FString InLoadSlotName)
{
	UE_MVVM_SET_PROPERTY_VALUE(LoadSlotName, InLoadSlotName);
}

void UAuraMVVM_LoadSlot::SetMapName(FString InPlayerName)
{
	UE_MVVM_SET_PROPERTY_VALUE(MapName, InPlayerName);
}

void UAuraMVVM_LoadSlot::SetPlayerLevel(int32 InPlayerLevel)
{
	UE_MVVM_SET_PROPERTY_VALUE(PlayerLevel, InPlayerLevel);
}
