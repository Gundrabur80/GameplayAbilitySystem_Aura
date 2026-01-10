// Copyright Martin Jakob


#include "UI/ViewModel/AuraMVVM_LoadSlot.h"

void UAuraMVVM_LoadSlot::InitializeSlot()
{
	// TODO: Check slot status based on loaded data
	SetWidgetSwitcherIndex.Broadcast(1);
}
