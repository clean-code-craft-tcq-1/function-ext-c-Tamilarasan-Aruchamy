typedef struct
{
	float Low_Critical_range;		// Lower Limit for Critical Alert
	float Low_Warning_range;		// Lower Limit for Warning
	float High_Warning_range;;		// Higher Limit for Warning
	float High_Critical_range;		// Higher Limit for Critical Alert
}BatteryLimitConfig;


typedef struct
{    // Index 0 - Alert in English 1 - Alert in German
	char Low_Critical_Alertmessage [2][50];// Alert message when orginal value is lower than min_range value
	char Low_Warning_Alertmessage [2][50];// Alert message when orginal value is > min_range and < normal_range value
	char Normal_Alertmessage [2][50];// Alert message when orginal value is in normal_range value
	char High_Warning_Alertmessage [2][50];// Alert message when orginal value is lower than min_range value
	char High_Critical_Alertmessage [2][50];// Alert message when orginal value is < max_range and > normal_range value
}BatteryAlertmessageConfig;



typedef struct
{    
	BatteryLimitConfig Limit;
	BatteryAlertmessageConfig Alertmessage;
}BatteryManagementConfig;
 


BatteryManagementConfig temperature_config=	\
{\
	{\
		0, 		/* Lower Limit for Critical Alert */ \
		10, 	/* Lower Limit for Warning */ \
		35,		/* Higher Limit for Warning */ \
		45		/* Higher Limit for Critical Alert */ \
	},\
	{  													/* Index 0-In English , 1- In German */ \
		{"LOW_TEMP_CRITICAL", "NIEDRIGE_TEMPERATUR_KRITISCH"},		/* Alertmessage when < Critical range */ \
		{"LOW_TEMP_WARNING", "WARNUNG BEI NIEDRIGEN TEMPERATUREN"},	/* Alertmessage when < Warning range */ \
		{"TEMP_NORMAL", "NORMALE TEMPERATUR"}, 							/* Message when Normal range */ \
		{"HIGH_TEMP_WARNING", "HOHE TEMPERATUR WARNUNG"},		/* Alertmessage when > Warning range */ \
		{"HIGH_TEMP_CRITICAL", "HOCH TEMPERATUR KRITISCH"}	/* Alertmessage when > Critical range */ \
	}\
};
				

BatteryManagementConfig soc_config=\
{\
	{\
		20,		/* Lower Limit for Critical Alert */ \
		40, 	/* Lower Limit for Warning */ \
		60,		/* Higher Limit for Warning */ \
		80		/* Higher Limit for Critical Alert */ \
	},\
	{  													/* Index 0-In English , 1- In German */ \
		{"LOW_SOC_CRITICAL", "NIEDRIGE_SOC_KRITISCH"},		/* Alertmessage when < Critical range */ \
		{"LOW_SOC_WARNING", "WARNUNG BEI NIEDRIGEN SOC"},			/* Alertmessage when < Warning range */ \
		{"SOC_NORMAL", "NORMALE SOC"}, 					/* Message when Normal range */ \
		{"HIGH_SOC_WARNING", "HOHE SOC WARNUNG"},		/* Alertmessage when > Warning range */ \
		{"HIGH_SOC_CRITICAL", "HOCH SOC KRITISCH"}		/* Alertmessage when > Critical range */ \
	}\
};
				

BatteryManagementConfig chargeRate_config=\
{\
	{\
		0, 		/* Lower Limit for Critical Alert */ \
		0.2,	/* Lower Limit for Warning */ \
		0.6,	/* Higher Limit for Warning */ \
		0.8		/* Higher Limit for Critical Alert */ \
	},\
	{  																/* Index 0-In English , 1- In German */ \
		{"LOW_CHANGERATE_CRITICAL", "NIEDRIGE_VERÄNDERN_KRITISCH"},		/* Alertmessage when < Critical range */ \
		{"LOW_CHANGERATE_WARNING", "WARNUNG BEI NIEDRIGEN VERÄNDERN"},		/* Alertmessage when < Warning range */ \
		{"CHANGERATE_NORMAL", "NORMALE VERÄNDERN"}, 				/* Message when Normal range */ \
		{"HIGH_CHANGERATE_WARNING", "HOHE VERÄNDERN WARNUNG"},		/* Alertmessage when > Warning range */ \
		{"HIGH_CHANGERATE_CRITICAL", "HOCH VERÄNDERN KRITISCH"}	/* Alertmessage when > Critical range */ \
	} 																\
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
