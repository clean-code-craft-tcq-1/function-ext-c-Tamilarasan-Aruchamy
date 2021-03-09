#include <stdio.h>
#include <assert.h>
#include "BatteryManagementConfig.h"


int alertIfBatteryInCriticalRange(float,BatteryManagementConfig);
int warnIfBatteryInWarningRange(float,BatteryManagementConfig);


int alertIfBatteryIsUnHealthy(float MeasuredValue, BatteryManagementConfig MinMaxMessage)
{
	if(alertIfBatteryInCriticalRange(MeasuredValue,MinMaxMessage)) 
	{
	return HEALTH_NOT_OK;
	}
	else if(warnIfBatteryInWarningRange(MeasuredValue,MinMaxMessage))
	{
	return HEALTH_NOT_OK;
	}
	printf("%s\n", MinMaxMessage.Alertmessage.Normal_Alertmessage[Alert_Language]);
	return HEALTH_OK;

}

int alertIfBatteryInCriticalRange(float MeasuredValue, BatteryManagementConfig CriticalRange)
{
	if(MeasuredValue < CriticalRange.Limit.Low_Critical_range) 
	{
    printf("%s\n", CriticalRange.Alertmessage.Low_Critical_Alertmessage[Alert_Language]);
	return 1;
	}
	else if(MeasuredValue > CriticalRange.Limit.High_Critical_range) 
	{
    printf("%s\n", CriticalRange.Alertmessage.High_Critical_Alertmessage[Alert_Language]);
	return 1;
	}
    return 0;

}

int warnIfBatteryInWarningRange(float MeasuredValue, BatteryManagementConfig WarningRange)
{
	if(MeasuredValue < WarningRange.Limit.Low_Warning_range) 
	{
    printf("%s\n", WarningRange.Alertmessage.Low_Warning_Alertmessage[Alert_Language]);
	return 1;
	}
	else if(MeasuredValue > WarningRange.Limit.High_Warning_range) 
	{
    printf("%s\n", WarningRange.Alertmessage.High_Warning_Alertmessage[Alert_Language]);
	return 1;
	}
    return 0;

}





int batteryIsOk(float temperature, float soc, float chargeRate) 
{
	return 	(
	
	alertIfBatteryIsUnHealthy(temperature, temperature_config) & \
	alertIfBatteryIsUnHealthy(soc, soc_config) & \
	alertIfBatteryIsUnHealthy(chargeRate, chargeRate_config));
			
}

int main() {
//Inputs - Temperature,State-of-Charge,Charge-rate
  assert( batteryIsOk( 20,  50,  0.4));		// Test Battery is Healthy
  
  assert(!batteryIsOk( 50,  50,  0.4)); 	//Test Battery Temperature is higher than critical error limit
  assert(!batteryIsOk( 20,  90,  0.4)); 	//Test Battery State-of-Charge is higher than critical error limit
  assert(!batteryIsOk( 20,  50,  1.0)); 	//Test Battery Charge-rate is higher than critical error limit
  assert(!batteryIsOk(-01,  50,  0.4));		//Test Battery Temperature is lower than critical error limit
  assert(!batteryIsOk( 20,  10,  0.4)); 	//Test Battery State-of-Charge is lower than critical error limit
  assert(!batteryIsOk( 20,  50, -1.0)); 	//Test Battery Charge-rate is lower than critical error limit
  
  assert(!batteryIsOk( 40,  50,  0.4));		//Test Battery Temperature is higher than warning limit and lower than critical error limit
  assert(!batteryIsOk( 20,  70,  0.4)); 	//Test Battery State-of-Charge is higher than warning limit and lower than critical error limit
  assert(!batteryIsOk( 20,  50,  0.7));		//Test Battery Charge-rate is higher than warning limit and lower than critical error limit
  assert(!batteryIsOk( 05,  50,  0.4)); 	//Test Battery Temperature is lower than warning limit and higher than critical error limit
  assert(!batteryIsOk( 20,  10,  0.4)); 	//Test Battery State-of-Charge is lower than warning limit and higher than critical error limit
  assert(!batteryIsOk( 20,  50,  0.1));		//Test Battery Charge-rate is lower than warning limit and higher than critical error limit
  
}
