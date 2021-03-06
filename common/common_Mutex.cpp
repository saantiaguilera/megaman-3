/*
 * Mutex.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: mastanca
 */

#include "common_Mutex.h"

#include <stddef.h>

Mutex::Mutex() {
	pthread_mutex_init(&myMutex, NULL);
}

Mutex::~Mutex() {
	pthread_mutex_destroy(&myMutex);
}

void Mutex::lock() {
	pthread_mutex_lock(&myMutex);
}

void Mutex::unlock() {
	pthread_mutex_unlock(&myMutex);
}
