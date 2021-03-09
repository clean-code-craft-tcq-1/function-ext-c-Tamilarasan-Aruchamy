typedef struct
{
	float Low_Critical_range;	// Lower Limit to alert critical error
	float Low_Warning_range;	// Lower Limit to warn
	float High_Warning_range; 	// Higher Limit to alert critical error
	float High_Critical_range;	// Higher Limit to warn
}BatteryLimitConfig;


typedef struct
{  // Index 0 - Alert in English 1 - Alert in German
	char Low_Critical_Alertmessage [2][50];	// Alert message when measured value is lower than Low_Critical_range
	char Low_Warning_Alertmessage [2][50];	// Warning message when measured value is < Low_Warning_range and > Low_Critical_range value
	char Normal_Alertmessage [2][50];	// Alert message when measured value is in normal_range value
	char High_Warning_Alertmessage [2][50];	// Warning message when measured value is > High_Warning_range and < High_Critical_range value
	char High_Critical_Alertmessage [2][50];// Alert message when measured value is Higher than High_Critical_range
}BatteryAlertmessageConfig;



typedef struct
{    
	BatteryLimitConfig Limit;
	BatteryAlertmessageConfig Alertmessage;
}BatteryManagementConfig;
 


BatteryManagementConfig temperature_config=	\
{\
	{  /* Here, Unit of temperature is Celsius" */ \
		0, 	/* Lower Limit for Critical Alert */ \
		10, 	/* Lower Limit for Warning */ \
		35,	/* Higher Limit for Warning */ \
		45	/* Higher Limit for Critical Alert */ \
	},\
	{  									/* Index 0-In English , 1- In German */ \
		{"LOW_TEMP_CRITICAL", "NIEDRIGE_TEMPERATUR_KRITISCH"},		/* Alert message when < Critical range */ \
		{"LOW_TEMP_WARNING", "WARNUNG BEI NIEDRIGEN TEMPERATUREN"},	/* Warning message when < Warning range */ \
		{"TEMP_NORMAL", "NORMALE TEMPERATUR"}, 				/* Message when Normal range */ \
		{"HIGH_TEMP_WARNING", "HOHE TEMPERATUR WARNUNG"},		/* Warning message when > Warning range */ \
		{"HIGH_TEMP_CRITICAL", "HOCH TEMPERATUR KRITISCH"}		/* Alert message when > Critical range */ \
	}\
};
				

BatteryManagementConfig soc_config=\
{\
	{\
		20,	/* Lower Limit for Critical Alert */ \
		40, 	/* Lower Limit for Warning */ \
		60,	/* Higher Limit for Warning */ \
		80	/* Higher Limit for Critical Alert */ \
	},\
	{  								/* Index 0-In English , 1- In German */ \
		{"LOW_SOC_CRITICAL", "NIEDRIGE_SOC_KRITISCH"},		/* Alert message when < Critical range */ \
		{"LOW_SOC_WARNING", "WARNUNG BEI NIEDRIGEN SOC"},	/* Warning message when < Warning range */ \
		{"SOC_NORMAL", "NORMALE SOC"}, 				/* Message when Normal range */ \
		{"HIGH_SOC_WARNING", "HOHE SOC WARNUNG"},		/* Warning message when > Warning range */ \
		{"HIGH_SOC_CRITICAL", "HOCH SOC KRITISCH"}		/* Alert message when > Critical range */ \
	}\
};
				

BatteryManagementConfig chargeRate_config=\
{\
	{\
		0, 	/* Lower Limit for Critical Alert */ \
		0.2,	/* Lower Limit for Warning */ \
		0.6,	/* Higher Limit for Warning */ \
		0.8	/* Higher Limit for Critical Alert */ \
	},\
	{  										/* Index 0-In English , 1- In German */ \
		{"LOW_CHANGERATE_CRITICAL", "NIEDRIGE_VERÄNDERN_KRITISCH"},		/* Alert message when < Critical range */ \
		{"LOW_CHANGERATE_WARNING", "WARNUNG BEI NIEDRIGEN VERÄNDERN"},		/* Warning message when < Warning range */ \
		{"CHANGERATE_NORMAL", "NORMALE VERÄNDERN"}, 				/* Message when Normal range */ \
		{"HIGH_CHANGERATE_WARNING", "HOHE VERÄNDERN WARNUNG"},			/* Warning message when > Warning range */ \
		{"HIGH_CHANGERATE_CRITICAL", "HOCH VERÄNDERN KRITISCH"}			/* Alert message when > Critical range */ \
	}\
};

enum Language
{
	English,
	German
};

int Alert_Language=English;

enum BatteryHealth{
	HEALTH_NOT_OK,
	HEALTH_OK
};
