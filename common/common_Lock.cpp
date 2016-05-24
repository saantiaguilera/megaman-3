/*
 * Lock.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: mastanca
 */

#include "common_Lock.h"

#include "common_Mutex.h"

Lock::Lock(Mutex &mutex) : aMutex(mutex) {
    aMutex.lock();
}

Lock::~Lock() {
	// Upon destruction of lock, mutex is disabled
    aMutex.unlock();
}

