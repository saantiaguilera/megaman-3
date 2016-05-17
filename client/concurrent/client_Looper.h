/*
 * client_MainLooper.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_CLIENT_LOOPER_H_
#define CLIENT_CLIENT_LOOPER_H_

#include "client_Runnable.h"
#include "../../common/common_Mutex.h"
#include <queue>
#include <vector>
#include <cstdlib>

#define MAX_GC_POOL_SIZE 5000 //Considering 1 Runnable costs us 10kb, this is 50mb

/**
 * Pasar a cpp
 *
 * Se puede hacer get y pop a la vez ? Me suena a que no asi que comparten el mutex
 */
class Looper {
private:
	Mutex mutex;
	std::queue<Runnable*> messagePool;
	std::vector<Runnable*> gcPool;

public:
    static Looper& getMainLooper() {
        static Looper instance;
        return instance;
    }

	Runnable * get() {
		Runnable *value;

		mutex.enableLock();
		value = messagePool.empty() ? NULL : messagePool.front();
		mutex.disableLock();

		return value;
	}

	void pop() {
		mutex.enableLock();
		if (!messagePool.empty()) {
			gcPool.push_back(messagePool.front());
			messagePool.pop();
		}
		mutex.disableLock();
	}

	void put(Runnable *runnable) {
		mutex.enableLock();
		messagePool.push(runnable);
		mutex.disableLock();

		//TODO IN ANOTHER THREAD DO THIZZ
		if (gcPool.size() > MAX_GC_POOL_SIZE)
			gc();
	}
private:
	Looper(Looper const&);
	void operator=(Looper const&);

	explicit Looper() { /* Dunno ? */ };

	void gc() {
		while (gcPool.size() > MAX_GC_POOL_SIZE) {
			delete (*gcPool.begin());
			gcPool.erase(gcPool.begin());
		}
	}
};



#endif /* CLIENT_CLIENT_LOOPER_H_ */
