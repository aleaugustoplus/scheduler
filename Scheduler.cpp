// Do not remove the include below
#include "Scheduler.h"
#include "Arduino.h"
#include "Motor.h"
#include "Time.h"
#include "Task.h"
#include <stdio.h>

#define NUM_TASKS 5

unsigned char dirLeft 	 = 0;
unsigned char dirRight	 = 0;
unsigned char speedLeft  = 0;
unsigned char speedRight = 0;
int MotorA=A0;
int MotorB=A1;
Motor *motor[2];
Task *Tasks[5];

void digitalClockDisplay();
void SendInfo();
void ReadMessage();
void Decode(char *Msg);
void DecClock(char *Msg);
void DecDaily(char *Msg);
void DecDate(char *Msg);
int GetInt(char *Msg, int *Pos, int Size);
long GetLong(char *Msg, int *Pos, int Size);

//-------- The setup function is called once at startup of the sketch-----------
void setup()
{

	Serial.begin(38400);


	motor[0]= new Motor(A0,A1);
	motor[1]= new Motor(A2,A3);


	setTime(12,45,00,20,02,2016);
	for(int x=0;x<NUM_TASKS;x++)
		Tasks[x]=0;



	Serial.println("Iniciado");
}

//--------- The loop function is called in an endless loop----------------------
void loop()
{


	for(int x=0;x<NUM_TASKS;x++)
		if(Tasks[x]!=0)
		 Tasks[x]->Verify();


	SendInfo();
	ReadMessage();
	delay(2000);
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
//------------------------------------------------------------------------------
void SendInfo()
{
 char Tmp[100];
 bool Active=false;
 sprintf(Tmp, "Relogio: %02d:%02d:%02d %02d/%02d/%04d", hour(), minute(), second(), day(), month(), year());
 Serial.println(Tmp);

 for(int x=0;x<NUM_TASKS;x++)
 {
	if(Tasks[x]!=0)
	{
		Tasks[x]->ToChar(Tmp);
		Serial.println(Tmp);



		Active=true;
	}
 }

 if(!Active)
	 Serial.println("Sem agendamentos!");

}
//------------------------------------------------------------------------------
void ReadMessage()
{
  char Msg[100];
  if(Serial.available())
  {
	  Serial.readBytesUntil('\n', Msg, 100);

	  Serial.println("Recebido!");
	  Decode(Msg);

  }
}
//------------------------------------------------------------------------------
void Decode(char *Msg)
{
	switch(Msg[0])
	{
	    //--Relogio--
		case 'A':
			DecClock(Msg);
		break;
		//--Data--
		case 'B':
			DecDate(Msg);
		break;
		//--Diario--
		case 'C':
			DecDaily(Msg);
		break;
		default:
			Serial.println("Falha ao decodificar!");
		break;

	}
}
//------------------------------------------------------------------------------
void DecClock(char *Msg)
{
  int Day, Month, Year, Hour, Minute, Second;
  int Pos=1;


  Day=GetInt(&Msg[Pos], &Pos,2);
  Month=GetInt(&Msg[Pos], &Pos,2);
  Year=GetInt(&Msg[Pos], &Pos,4);


  Hour=GetInt(&Msg[Pos], &Pos,2);
  Minute=GetInt(&Msg[Pos], &Pos,2);
  Second=GetInt(&Msg[Pos], &Pos,2);


  setTime(Hour,Minute,Second,Day,Month,Year);

}
//------------------------------------------------------------------------------
void DecDaily(char *Msg)
{
	int Hour, Minute;
	long Delay;
	int Pos=1, PosMotor;
//C16510000200001

	Serial.println("Daily");

	Hour=GetInt(&Msg[Pos], &Pos,2);
	Minute=GetInt(&Msg[Pos], &Pos,2);
	Delay=GetLong(&Msg[Pos], &Pos,10);
	PosMotor=GetInt(&Msg[Pos], &Pos,2);

	if(Tasks[0]!=NULL)
		delete  Tasks[0];
	Tasks[0]=new Task(Hour,Minute, Delay, motor[PosMotor-1]);
}
//------------------------------------------------------------------------------
void DecDate(char *Msg)
{
	int Hour, Minute;
	long Delay;
	int Day, Month, Year;
	int Pos=1, PosMotor;
	//B250220161845000000200001

	Day=GetInt(&Msg[Pos], &Pos,2);
    Month=GetInt(&Msg[Pos], &Pos,2);
    Year=GetInt(&Msg[Pos], &Pos,4);

	Hour=GetInt(&Msg[Pos], &Pos,2);
	Minute=GetInt(&Msg[Pos], &Pos,2);

	Delay=GetLong(&Msg[Pos], &Pos,10);
	PosMotor=GetInt(&Msg[Pos], &Pos,2);

	if(Tasks[0]!=NULL)
		delete Tasks[0];

	Tasks[0]=new Task(Hour,Minute, Day, Month, Year, Delay, motor[PosMotor-1]);

}
//------------------------------------------------------------------------------
int GetInt(char *Msg, int *Pos, int Size)
{
  char Tmp[20];
  memset(Tmp,0,sizeof(Tmp));
  memcpy(Tmp, Msg, Size);
  *Pos=*Pos+Size;
  return atoi(Tmp);
}
//------------------------------------------------------------------------------
long GetLong(char *Msg, int *Pos, int Size)
{
  char Tmp[20];
  memset(Tmp,0,sizeof(Tmp));
  memcpy(Tmp, Msg, Size);
  *Pos=*Pos+Size;
  return atol(Tmp);
}
//------------------------------------------------------------------------------
