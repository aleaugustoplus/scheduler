/*
 * Motor.cpp
 *
 *  Created on: Feb 19, 2016
 *      Author: root
 */

#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int PinA, int PinB, DIR dir)
{
	this->PinA=PinA;
	this->PinB=PinB;
	this->dir=dir;
	Running=false;
	pinMode(PinA, OUTPUT);
	pinMode(PinB, OUTPUT);

	this->Stop();
}
//------------------------------------------------------------------------------
Motor::~Motor()
{
	this->Stop();
}
//------------------------------------------------------------------------------
void Motor::SetDir(DIR dir)
{
	this->dir=dir;

	if(Running)
		this->Run();
}
//------------------------------------------------------------------------------
void Motor::Run()
{
	if(dir==DIR_FRONT)
	{
		digitalWrite(PinA, HIGH);
		digitalWrite(PinB, LOW);
	}
	else
	{
		digitalWrite(PinA, LOW);
		digitalWrite(PinB, HIGH);
	}

	Running=true;
}
//------------------------------------------------------------------------------
void Motor::Stop()
{
	Running=false;
	digitalWrite(PinA, LOW);
	digitalWrite(PinB, LOW);
}
//------------------------------------------------------------------------------
