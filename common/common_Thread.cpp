/*
 * Thread.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: mastanca
 */

#include "common_Thread.h"

#include <stddef.h>

Thread::~Thread() {
}

void Thread::start() {
	pthread_create(&myThread, NULL, Thread::runner, this);
}

void Thread::join() {
	pthread_join(myThread, NULL);
}

void* Thread::runner(void *data) {
    Thread *self = (Thread*)data;
    self->run();
    return data;
}
