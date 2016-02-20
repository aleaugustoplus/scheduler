/*
 * Motor.h
 *
 *  Created on: Feb 19, 2016
 *      Author: root
 */

#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {

public:
	enum DIR{ DIR_FRONT,
		      DIR_REV
	};
private:
	int PinA;
	int PinB;
	DIR dir;
	bool Running;

public:
	Motor(int PinA, int PinB, DIR=DIR_FRONT);
	virtual ~Motor();

	void SetDir(DIR);
	void Run();
	void Stop();

};

#endif /* MOTOR_H_ */
