#include <stdio.h>

int mainController(int BatteryHealthStatus,char AlertMessage[])
{

printf("%s",AlertMessage); // Printing the Battery Alert messages 

if(BatteryHealthStatus)
	return 1;
else
	return 0;


}
