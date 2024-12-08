// Copyright Martin Jakob


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCOParams)
{
	PlayerController = WCOParams.PlayerController;
	PlayerState = WCOParams.PlayerState;
	AbilitySystemComponent = WCOParams.AbilitySystemComponent;
	AttributeSet = WCOParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
}
