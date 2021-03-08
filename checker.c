#include <stdio.h>
#include <assert.h>
#include "BatteryManagementConfig.h"

int alertIfBatteryIsUnHealthy(float MeasuredValue, BatteryManageConfig MinMaxMessage)
{
	if(MeasuredValue < MinMaxMessage.min_range) 
	{
    printf("%s\n", MinMaxMessage.Min_Alertmessage);
	return HEALTH_NOT_OK;
	}
	else if(MeasuredValue > MinMaxMessage.max_range) 
	{
    printf("%s\n", MinMaxMessage.Max_Alertmessage);
	return HEALTH_NOT_OK;
	}
    return HEALTH_OK;

}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
	return 	(alertIfBatteryIsUnHealthy(temperature, temperature_config) & \
			alertIfBatteryIsUnHealthy(soc, soc_config) & \
			alertIfBatteryIsUnHealthy(chargeRate, chargeRate_config));
			
}

int main() {
//Temperature,State-of-Charge,Charge-rate
  assert(batteryIsOk(25, 70, 0.7)); // Test Battery is Healthy
  assert(!batteryIsOk(50, 70, 0.7)); //Test Battery Temperature is higher than limit
  assert(!batteryIsOk(25, 85, 0.7)); //Test Battery State-of-Charge is higher than limit
  assert(!batteryIsOk(25, 70, 1)); //Test Battery Charge-rate is higher than limit
  assert(!batteryIsOk(-1, 70, 0.7)); //Test Battery Temperature is lower than limit
  assert(!batteryIsOk(25, 15, 0.7)); //Test Battery State-of-Charge is lower than limit
  assert(!batteryIsOk(25, 70, -1)); //Test Battery Charge-rate is lower than limit
  
}
