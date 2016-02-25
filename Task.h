/*
 * Task.h
 *
 *  Created on: Feb 19, 2016
 *      Author: root
 */

#ifndef TASK_H_
#define TASK_H_

#include "Motor.h"

class Task
{
public:
	enum Type{ DAILY,
		  	   DATE,
	};
private:

	int Hour;
	int Minute;
	int Day;
	int Month;
	int Year;
	long TimeOn;
	int ExecDaily;
	Motor *motor;
	Type type;


	void ExecuteEvent();
	bool CheckDaily();
	bool CheckDate();
public:
	Task(Type type, Motor *motor);
	Task(int Hour, int Minute, long TimeOn, Motor *motor);
	Task(int Hour, int Minute, int Day, int Month, int Year, long TimeOn, Motor *motor);

	virtual ~Task();
	void Verify();

	void ToChar(char *);
	int getDay();
	void setDay(int day);
	int getHour();
	void setHour(int hour);
	int getMinute();
	void setMinute(int minute);
	int getMonth();
	void setMonth(int month);
	long getTimeOn();
	void setTimeOn(long timeOn);
	Type getType();
	void setType(Type type);
	int getYear();
	void setYear(int year);

};

#endif /* TASK_H_ */
