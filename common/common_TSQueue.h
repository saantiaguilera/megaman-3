/*
 * common_TSQueue.h
 *
 *  Created on: May 25, 2016
 *      Author: mastanca
 */

#ifndef COMMON_COMMON_TSQUEUE_H_
#define COMMON_COMMON_TSQUEUE_H_

#include <queue>

#include "common_Lock.h"
#include "common_Mutex.h"

template <class T>
class TSQueue {
private:
	// Mutex for locking shared resource
	Mutex mutex;
	// The actual structure holding the queue
	std::queue<T> self;
public:
	// Constructor
	TSQueue();
	// Destroyer
	virtual ~TSQueue();
	// Push data into the queue
	void push_back(T const&);
	// Get the first element, removing it
	T pop_front();
	// Get the actual queue
	std::queue<T>* getQueue();
private:
	// Copy constructor
	TSQueue(const TSQueue&);
	// Assignment operator
	TSQueue& operator=(const TSQueue&);
};

template<class T>
inline TSQueue<T>::TSQueue() {
}

template<class T>
inline TSQueue<T>::~TSQueue() {
}

template<class T>
inline void TSQueue<T>::push_back(const T&) {
	Lock lock(mutex);
	self.push(T);
}

template<class T>
inline T TSQueue<T>::pop_front() {
	Lock lock(mutex);
	T return_element = self.front();
	self.pop();
	return return_element;
}

template<class T>
inline std::queue<T>* TSQueue<T>::getQueue() {
	return &self;
}

#endif /* COMMON_COMMON_TSQUEUE_H_ */
