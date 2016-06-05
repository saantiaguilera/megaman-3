/*
 * Lock.h
 *
 *  Created on: Apr 12, 2016
 *      Author: mastanca
 */

#ifndef SRC_LOCK_H_
#define SRC_LOCK_H_

class Mutex;

class Lock {
private:
        Mutex &aMutex;
public:
        // Constructor, reserves the current scope for the working thread
        explicit Lock(Mutex &aMutex);
        // Destroyer, enables scope for other threads to run
        ~Lock();
};

#endif /* SRC_LOCK_H_ */
