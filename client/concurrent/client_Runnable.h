/*
 * client_Runnable.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_CLIENT_RUNNABLE_H_
#define CLIENT_CLIENT_RUNNABLE_H_

class Runnable {
public:
	Runnable() {};
	virtual ~Runnable() {};

	virtual void operator() () = 0;
private:
	Runnable(const Runnable&);
	Runnable& operator=(const Runnable&);
};



#endif /* CLIENT_CLIENT_RUNNABLE_H_ */
