
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
	printf("\n\t%s", MinMaxMessage.Alertmessage.Normal_Alertmessage[Alert_Language]);
	return HEALTH_OK;

}

int alertIfBatteryInCriticalRange(float MeasuredValue, BatteryManagementConfig CriticalRange)
{
	if(MeasuredValue < CriticalRange.Limit.Low_Critical_range) 
	{
    printf("\n\t%s", CriticalRange.Alertmessage.Low_Critical_Alertmessage[Alert_Language]);
	return 1;
	}
	else if(MeasuredValue > CriticalRange.Limit.High_Critical_range) 
	{
    printf("\n\t%s", CriticalRange.Alertmessage.High_Critical_Alertmessage[Alert_Language]);
	return 1;
	}
    return 0;

}

int warnIfBatteryInWarningRange(float MeasuredValue, BatteryManagementConfig WarningRange)
{
	if(MeasuredValue < WarningRange.Limit.Low_Warning_range) 
	{
    printf("\n\t%s", WarningRange.Alertmessage.Low_Warning_Alertmessage[Alert_Language]);
	return 1;
	}
	else if(MeasuredValue > WarningRange.Limit.High_Warning_range) 
	{
    printf("\n\t%s", WarningRange.Alertmessage.High_Warning_Alertmessage[Alert_Language]);
	return 1;
	}
    return 0;

}





int batteryIsOk(float temperature, char temperature_unit, float soc, float chargeRate) 
{
	if(temperature_unit=='F')
	{
		temperature=((temperature-32) * ((float)5/9));   // Converting Fahrenheit to Celsius
	}
	else
	{
		temperature=temperature;
	}
	
	
	return 	(
	
	alertIfBatteryIsUnHealthy(temperature, temperature_config) & \
	alertIfBatteryIsUnHealthy(soc, soc_config) & \
	alertIfBatteryIsUnHealthy(chargeRate, chargeRate_config));
			
}

int main() {
/*Inputs - 	parameter 1 - Tmperature
		parameter 2 - Tmperature Unit, "C = Celsius", "F=fahrenheit"	
		parameter 3 - State-of-Charge		
		parameter 4 - Charge-rate	 */	

#define TEST_CASE(a) printf("\nTest_Case_%d",a);


TEST_CASE(1);  	assert( batteryIsOk( 68, 'F', 50,  0.4));	// Test Battery is Healthy
  
TEST_CASE(2);  	assert(!batteryIsOk( 50, 'C', 50,  0.4)); 	//Test Battery Temperature is higher than critical error limit
TEST_CASE(3);  	assert(!batteryIsOk( 20, 'C',  90,  0.4)); 	//Test Battery State-of-Charge is higher than critical error limit
TEST_CASE(4);  	assert(!batteryIsOk( 20, 'C',  50,  1.0)); 	//Test Battery Charge-rate is higher than critical error limit
TEST_CASE(5);  	assert(!batteryIsOk(-01, 'C',  50,  0.4));	//Test Battery Temperature is lower than critical error limit
TEST_CASE(6);  	assert(!batteryIsOk( 20, 'C',  10,  0.4)); 	//Test Battery State-of-Charge is lower than critical error limit
TEST_CASE(7);  	assert(!batteryIsOk( 20, 'C',  50, -1.0)); 	//Test Battery Charge-rate is lower than critical error limit
  
TEST_CASE(8);  	assert(!batteryIsOk( 40, 'C',  50,  0.4));	//Test Battery Temperature is higher than warning limit and lower than critical error limit
TEST_CASE(9);  	assert(!batteryIsOk( 20, 'C',  70,  0.4)); 	//Test Battery State-of-Charge is higher than warning limit and lower than critical error limit
TEST_CASE(10);  assert(!batteryIsOk( 20, 'C',  50,  0.7));	//Test Battery Charge-rate is higher than warning limit and lower than critical error limit
TEST_CASE(11);  assert(!batteryIsOk( 05, 'C',  50,  0.4)); 	//Test Battery Temperature is lower than warning limit and higher than critical error limit
TEST_CASE(12);  assert(!batteryIsOk( 20, 'C',  10,  0.4)); 	//Test Battery State-of-Charge is lower than warning limit and higher than critical error limit
TEST_CASE(13);  assert(!batteryIsOk( 20, 'C',  50,  0.1));	//Test Battery Charge-rate is lower than warning limit and higher than critical error limit
  
}
