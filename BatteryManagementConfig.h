typedef struct
{
	float min_range;		// Lower Limit for BatteryHealth check
	float max_range;		// Higher Limit for BatteryHealth check
	char Min_Alertmessage[50];	// Alert message when orginal value is lower than min_range value
	char Max_Alertmessage[50];	// Alert message when orginal value is higher than max_range value
}BatteryManageConfig;


BatteryManageConfig temperature_config={0,45,"Temperature is very low!","Temperature is very High!"};
BatteryManageConfig soc_config={20,80,"State of Charge is very low!","State of Charge is very High!"};
BatteryManageConfig chargeRate_config={0,0.8,"Charge Rate is very low!","Charge Rate is very High!"};

enum BatteryHealth{
	HEALTH_NOT_OK,
	HEALTH_OK
};
