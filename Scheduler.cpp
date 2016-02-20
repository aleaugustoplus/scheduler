// Do not remove the include below
#include "Scheduler.h"
#include "Arduino.h"
#include "Motor.h"
#include "Time.h"
#include "Task.h"

#define NUM_TASKS 5

unsigned char dirLeft 	 = 0;
unsigned char dirRight	 = 0;
unsigned char speedLeft  = 0;
unsigned char speedRight = 0;
int MotorA=A0;
int MotorB=A1;
Motor *motor;
Task *Tasks[5];

void digitalClockDisplay();

//-------- The setup function is called once at startup of the sketch-----------
void setup()
{

	Serial.begin(38400);
	Serial.println("ok 1");

	motor= new Motor(A0,A1);


	setTime(12,45,00,20,02,2016);
	for(int x=0;x<NUM_TASKS;x++)
		Tasks[x]=0;

	Tasks[0]=new Task(12,46, 20000, motor);

	Serial.println("Fim Setup");
}

//--------- The loop function is called in an endless loop----------------------
static int Tmp=0;
void loop()
{



	Serial.println("Loop");

	for(int x=0;x<NUM_TASKS;x++)
		if(Tasks[x]!=0)
		 Tasks[x]->Verify();


	digitalClockDisplay();
	delay(5000);


}
//------------------------------------------------------------------------------
void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}
