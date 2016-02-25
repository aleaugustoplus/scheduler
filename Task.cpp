/*
 * Task.cpp
 *
 *  Created on: Feb 19, 2016
 *      Author: root
 */

#include "Task.h"
#include "Time.h"
#include <Arduino.h>
//------------------------------------------------------------------------------
Task::Task(Type type, Motor *motor)
{
	this->Hour=0;
	this->Minute=0;
	this->TimeOn=0;
	this->Day=0;
	this->Month=0;
	this->Year=0;
	this->type=type;
	this->motor=motor;
	this->ExecDaily=100;
}
//------------------------------------------------------------------------------
Task::Task(int Hour, int Minute, long TimeOn, Motor *motor)
{
	this->Hour=Hour;
	this->Minute=Minute;
	this->TimeOn=TimeOn;
	this->Day=0;
	this->Month=0;
	this->Year=0;
	type=DAILY;
	this->motor=motor;
	this->ExecDaily=100;
}
//------------------------------------------------------------------------------
Task::Task(int Hour, int Minute, int Day, int Month, int Year, long TimeOn, Motor *motor)
{
	this->Hour=Hour;
	this->Minute=Minute;
	this->TimeOn=TimeOn;
	this->Day=Day;
	this->Month=Month;
	this->Year=Year;
	type=DATE;
	this->motor=motor;
	this->ExecDaily=100;
}
//------------------------------------------------------------------------------
Task::~Task()
{

}
//------------------------------------------------------------------------------
void Task::Verify()
{
	bool Event=false;
	switch(type)
	{
		case DAILY:
				Event=this->CheckDaily();
		break;
		case DATE:
				Event=this->CheckDate();
		break;

	}

	if(Event)
		this->ExecuteEvent();
}
//------------------------------------------------------------------------------
bool Task::CheckDaily()
{

	if(Hour==hour() && Minute==minute() && ExecDaily!=day())
	{
		ExecDaily=day();
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
bool Task::CheckDate()
{
	if(Hour==hour() && Minute==minute() && Day==day() && Month==month() && Year==year() && ExecDaily!=day())
	{
		ExecDaily=day();
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
void Task::ToChar(char *Msg)
{
	switch(type)
	{
		case DAILY:
			   sprintf(Msg,"Agendado diario: %02d:%02d Tempo Ligado: %u", Hour, Minute, TimeOn);
		break;
		case DATE:
			   sprintf(Msg,"Agendado Data: %02d:%02d %02d/%02d/%04d Tempo Ligado: %u", Hour, Minute, Day, Month, Year, TimeOn);
		break;

	}
}
//------------------------------------------------------------------------------
void Task::ExecuteEvent()
{
	motor->Run();
	delay(TimeOn);
	motor->Stop();
}
//------------------------------------------------------------------------------
int Task::getDay()
{
	return Day;
}
//------------------------------------------------------------------------------
void Task::setDay(int day)
{
	Day = day;
}
//------------------------------------------------------------------------------
int Task::getHour()
{
	return Hour;
}
//------------------------------------------------------------------------------
void Task::setHour(int hour)
{
	Hour = hour;
}
//------------------------------------------------------------------------------
int Task::getMinute()
{
	return Minute;
}
//------------------------------------------------------------------------------
void Task::setMinute(int minute)
{
	Minute = minute;
}
//------------------------------------------------------------------------------
int Task::getMonth()
{
	return Month;
}
//------------------------------------------------------------------------------
void Task::setMonth(int month)
{
	Month = month;
}
//------------------------------------------------------------------------------
long Task::getTimeOn()
{
	return TimeOn;
}
//------------------------------------------------------------------------------
void Task::setTimeOn(long timeOn)
{
	TimeOn = timeOn;
}
//------------------------------------------------------------------------------
Task::Type Task::getType()
{
	return type;
}
//------------------------------------------------------------------------------
void Task::setType(Type type)
{
	this->type = type;
}
//------------------------------------------------------------------------------
int Task::getYear()
{
	return Year;
}
//------------------------------------------------------------------------------
void Task::setYear(int year)
{
	Year = year;
}
//------------------------------------------------------------------------------

