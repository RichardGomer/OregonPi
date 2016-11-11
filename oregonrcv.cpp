/* ===================================================
C code : test.cpp
* ===================================================
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "RCSwitch.h"
#include "RcOok.h"
#include "Sensor.h"

int main(int argc, char *argv[])
{
	setbuf(stdout,NULL);

	int RXPIN = 1;
	int TXPIN = 0;

	if(wiringPiSetup() == -1)
		return 0;

	RCSwitch *rc = new RCSwitch(RXPIN,TXPIN);

	while (1)
	{
		if (rc->OokAvailable())
		{
			char message[100];

			rc->getOokCode(message);
			printf("%s\n",message);

			Sensor *s = Sensor::getRightSensor(message);
			if (s!= NULL)
			{
				printf("%d: %f\n", s->getChannel(), s->getTemperature());
				//printf("Temp : %f\n",s->getTemperature());
				//printf("Channel : %d\n",s->getChannel());
			}
			delete s;
		}
		delay(200);
	}
}
